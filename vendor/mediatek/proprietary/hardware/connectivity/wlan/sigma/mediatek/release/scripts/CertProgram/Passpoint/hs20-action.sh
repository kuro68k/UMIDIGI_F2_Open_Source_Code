#!/system/bin/sh
# HotSpot2.0 Release 2 action script - hs20-action.sh
# Supports the testing of wpa_supplicant and wlan driver
# support for HotSpot2.0 Release 2 on Android.
# It assumes that busybox is installed.
# Copyright (c) 2014, Qualcomm Atheros, Inc.
# All Rights Reserved.
# Licensed under the Clear BSD license. See README for more details.

BASEDIR=$(dirname $0)
date >> $BASEDIR/Logs/hs20-action.log
echo "$*" >> $BASEDIR/Logs/hs20-action.log
if [ -e $BASEDIR/summary ]; then
    echo "$*" >> $BASEDIR/summary
fi
IFNAME=$1
CMD=$2

echo "CMD=$CMD"

echo "CMD=$CMD" >> $BASEDIR/Logs/hs20-action.log

IFACE_DIR=/data/vendor/wifi/wpa/sockets/

run_eloop_cmd()
{
rm -f $BASEDIR/Logs/e_loop.log
echo "$1" > $BASEDIR/tag_file

# Read back the status of the command issued to e_loop

i=1
while [ ! -e $BASEDIR/Logs/e_loop.log  ]
do
        sleep 1
        echo "Waiting $i second(s) for result..." >> $BASEDIR/Logs/hs20-action.log
        if [ "$i" = "30" ] ; then
        echo "Something went wrong with e_loop, exiting" >> $BASEDIR/Logs/hs20-action.log
        exit 0
        fi
        i=$(($i + 1))
done

cmd=$(grep "ELOOP_CMD :" $BASEDIR/Logs/e_loop.log)
status=$(grep "ELOOP_CMD_STATUS :"  $BASEDIR/Logs/e_loop.log)
echo "Eloop: $cmd ; $status" >> $BASEDIR/Logs/hs20-action.log
}

if [ "$CMD" = "HS20-SUBSCRIPTION-REMEDIATION" ]; then
    METHOD="$3"
    URL="$4"
    cd $BASEDIR
    date >> $BASEDIR/Logs/hs20-osu-client.txt
    echo "METHOD=$METHOD" >> $BASEDIR/Logs/hs20-osu-client.txt
    echo "URL=$URL" >> $BASEDIR/Logs/hs20-osu-client.txt
    if [ -e $BASEDIR/SP/wi-fi.org/pps.xml ]; then
	nohup hs20-osu-client -w $IFACE_DIR -r hs20-osu-client.res -s summary -dddKt -f $BASEDIR/Logs/hs20-osu-client.txt sub_rem $URL $BASEDIR/SP/wi-fi.org/pps.xml $BASEDIR/SP/wi-fi.org/ca.pem >> $BASEDIR/Logs/browser.txt 2>&1 &
    else
        if [ "$METHOD" = "0" ]; then
            hs20-osu-client -w $IFACE_DIR -r hs20-osu-client.res -s summary -dddKt -f Logs/hs20-osu-client.txt oma_dm_sim_prov $URL osu-ca.pem
        else
            hs20-osu-client -w $IFACE_DIR -r hs20-osu-client.res -s summary -dddKt -f Logs/hs20-osu-client.txt sim_prov $URL osu-ca.pem
        fi
    fi
    RES=$?
    if [ -r hs20-osu-client.res ]; then
#        notify-send "'cat hs20-osu-client.res'"
        echo "hs20-osu-client: 'cat hs20-osu-client.res'" >> summary
    elif [ "$RES" = "0" ]; then
        echo "hs20-osu-client success" >> summary
    else
        echo "hs20-osu-client error" >> summary
    fi
    date >> Logs/hs20-osu-client.txt
fi

if [ "$CMD" = "CONNECTED" ]; then
    if [ -e $BASEDIR/static-ip ]; then
	if read ver addr mask gw < $BASEDIR/static-ip; then
	    echo "ver=$ver addr=$addr mask=$mask gw=$gw" >> $BASEDIR/Logs/hs20-action.log
	    if [ "$ver" = "6" ]; then

		run_eloop_cmd "busybox sysctl -w net.ipv6.conf.$IFNAME.accept_dad=2 net.ipv6.conf.$IFNAME.dad_transmits=4 net.ipv6.conf.$IFNAME.autoconf=0 net.ipv6.conf.$IFNAME.ndisc_notify=1"
		run_eloop_cmd "ip -6 addr del $addr/$mask dev $IFNAME"
		run_eloop_cmd "busybox sysctl -w net.ipv6.conf.$IFNAME.disable_ipv6=0"
		run_eloop_cmd "ip -6 addr add $addr/$mask dev $IFNAME"
		sleep 4

		run_eloop_cmd "ip addr show dev $IFNAME"
		if [[ ! -z $(busybox grep -i $addr $BASEDIR/Logs/e_loop.log | grep -i dadfailed ) ]] ; then
		    echo "Duplicate IPv6 address $addr found on $IFNAME" >> $BASEDIR/Logs/hs20-action.log
		    #I need a version of the "notify-send" command that works in Android
		    #notify-send "Duplicate IPv6 address $addr found on $IFNAME"
		    exit 0
		fi
		if [[ -z $(grep -i $addr $BASEDIR/Logs/e_loop.log) ]] ; then
		    echo "Could not assign the requested IPv6 address $addr on $IFNAME" >> $BASEDIR/Logs/hs20-action.log
		    #notify-send "Could not assign the requested IPv6 address $addr on $IFNAME"
		    exit 0
		fi
	    else
		echo "Cleaning up and Sleeping 4 seconds..." >> $BASEDIR/Logs/hs20-action.log
		rm -f $BASEDIR/Logs/e_loop.log
		sleep 4
		echo "Waking up..." >> $BASEDIR/Logs/hs20-action.log
		run_eloop_cmd "busybox arping -c 4 -D -I $IFNAME -s 0.0.0.0 $addr"
		#Search for the string "Unicast reply".  Then you know you have a duplicate IP address...
		if [[ ! -z $(grep Unicast $BASEDIR/Logs/e_loop.log) ]] ; then
		    echo "Duplicate IPv4 address $addr found on $IFNAME" >> $BASEDIR/Logs/hs20-action.log
		    #notify-send "Duplicate IPv4 address $addr found on $IFNAME"
		    exit 0
		else
		    echo "Duplicate IPv4 address $addr NOT found on $IFNAME. Configuring address." >> $BASEDIR/Logs/hs20-action.log
		fi
		ifconfig $IFNAME $addr netmask $mask
		run_eloop_cmd "busybox arping -c 4 -I $IFNAME -s $addr $addr"
		if [ "$gw" != "N/A" ]; then
		    route add default gw "$gw"
		    ip ro re default via "$gw"
		fi
	    fi
	else
	    echo "Could not parse static-ip" >> $BASEDIR/Logs/hs20-action.log
	fi
	exit
    fi

    run_eloop_cmd "busybox sysctl -w net.ipv6.conf.$IFNAME.disable_ipv6=1 net.ipv6.conf.$IFNAME.autoconf=1 net.ipv6.conf.$IFNAME.accept_ra=1 net.ipv6.conf.$IFNAME.ndisc_notify=1 net.ipv6.conf.$IFNAME.disable_ipv6=0"
    echo "DHCP/stateless IP configuration" >> $BASEDIR/Logs/hs20-action.log
    #Fix the next line to use IFNAME
    run_eloop_cmd "kill `cat /data/misc/dhcp/dhcpcd-wlan0.pid`"

    #/system/bin/dhcpcd -ABKLG -f /system/etc/dhcpcd/dhcpcd.conf -h android-eaaffd5197248a27 $IFNAME
    /system/bin/dhcpcd -ABKLG -f /system/etc/dhcpcd/dhcpcd.conf $IFNAME
    #The above line replaces this line:
    #dhclient -nw -pf /var/run/dhclient-$IFNAME.pid $IFNAME
    #This does not really work properly after DHCP, i.e., this would need to be
    #within dhcp-script.
    #sleep 2
    #ip addr show dev $IFNAME >> $BASEDIR/Logs/hs20-action.log
    #addr=`ip addr show dev $IFNAME | grep "inet " | sed "s%.*inet \([^/]*\)/.*%\1%"`
    #if [ -n "$addr" ]; then
	#arping -I $IFNAME -D $addr -c 3 >> $BASEDIR/Logs/hs20-action.log 2>&1
    #fi

fi

if [ "$CMD" = "DISCONNECTED" ]; then
    if [ -e $BASEDIR/static-ip ]; then
	exit
    fi
    #kill_daemon dhclient /var/run/dhclient-$IFNAME.pid
    #Fix the next line to use IFNAME
    run_eloop_cmd "kill `cat /data/misc/dhcp/dhcpcd-wlan0.pid`"
fi

if [ "$CMD" = "ESS-DISASSOC-IMMINENT" ]; then
    cd $BASEDIR
    PMF="$3"
    TIME_IN_MS="$4"
    URL="$5"
    if [ "$PMF" = "0" ]; then
	echo "Disassociation imminent notification received without PMF - ignored"
	exit 0
    fi
    echo "Disassociation imminent notification received - URL: $URL"
    if ! busybox pidof hs20-osu-client; then
	sleep 1
	nohup hs20-osu-client -w $IFACE_DIR -f Logs/hs20-osu-client.txt browser $URL > Logs/browser.txt 2>&1 &
    fi
#    notify-send "Disassociation imminent"
fi

if [ "$CMD" = "HS20-DEAUTH-IMMINENT-NOTICE" ]; then
    cd $BASEDIR
    CODE="$3"
    DELAY="$4"
    URL="$5"
    count=1
    echo "HS 2.0 Deauthentication Imminent notification received - code=$CODE reauth_delay=$DELAY URL: $URL"
    case "$URL" in
	http*)
	    #while [ $count -le 2 ]
	    #do
		#sleep 1
		#addr=$(busybox ip addr show dev $IFNAME | grep "inet ")
		#if [ -n "$addr" ]; then
		#if ! busybox pidof hs20-osu-client; then
		#nohup hs20-osu-client -w $IFACE_DIR -f Logs/hs20-osu-client.txt browser $URL > Logs/browser.txt 2>&1 &
		#fi
		#    break
		#else
		#    echo "waiting $count seconds"
		#fi
		#count=$(($count + 1))
	    #done
	    if ! busybox pidof hs20-osu-client; then
    	sleep 1
    	nohup hs20-osu-client -w $IFACE_DIR -f Logs/hs20-osu-client.txt browser $URL > Logs/browser.txt 2>&1 &
    	echo "Launch hs20-osu-client"
        fi
	    ;;
    esac
#    notify-send "HS 2.0 Deauthentication imminent"
fi
