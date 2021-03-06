#
# Copyright (c) 2014-2018, ARM Limited and Contributors. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

# Cortex A57 specific optimisation to skip L1 cache flush when
# cluster is powered down.
SKIP_A57_L1_FLUSH_PWR_DWN	?=0

# Flag to disable the cache non-temporal hint.
# It is enabled by default.
A53_DISABLE_NON_TEMPORAL_HINT	?=1

# Flag to disable the cache non-temporal hint.
# It is enabled by default.
A57_DISABLE_NON_TEMPORAL_HINT	?=1

WORKAROUND_CVE_2017_5715	?=1
WORKAROUND_CVE_2018_3639	?=1
DYNAMIC_WORKAROUND_CVE_2018_3639	?=0

# Process SKIP_A57_L1_FLUSH_PWR_DWN flag
$(eval $(call assert_boolean,SKIP_A57_L1_FLUSH_PWR_DWN))
$(eval $(call add_define,SKIP_A57_L1_FLUSH_PWR_DWN))

# Process A53_DISABLE_NON_TEMPORAL_HINT flag
$(eval $(call assert_boolean,A53_DISABLE_NON_TEMPORAL_HINT))
$(eval $(call add_define,A53_DISABLE_NON_TEMPORAL_HINT))

# Process A57_DISABLE_NON_TEMPORAL_HINT flag
$(eval $(call assert_boolean,A57_DISABLE_NON_TEMPORAL_HINT))
$(eval $(call add_define,A57_DISABLE_NON_TEMPORAL_HINT))

# Process WORKAROUND_CVE_2017_5715 flag
$(eval $(call assert_boolean,WORKAROUND_CVE_2017_5715))
$(eval $(call add_define,WORKAROUND_CVE_2017_5715))

# Process WORKAROUND_CVE_2018_3639 flag
$(eval $(call assert_boolean,WORKAROUND_CVE_2018_3639))
$(eval $(call add_define,WORKAROUND_CVE_2018_3639))

$(eval $(call assert_boolean,DYNAMIC_WORKAROUND_CVE_2018_3639))
$(eval $(call add_define,DYNAMIC_WORKAROUND_CVE_2018_3639))

ifneq (${DYNAMIC_WORKAROUND_CVE_2018_3639},0)
    ifeq (${WORKAROUND_CVE_2018_3639},0)
        $(error "Error: WORKAROUND_CVE_2018_3639 must be 1 if DYNAMIC_WORKAROUND_CVE_2018_3639 is 1")
    endif
endif

# CPU Errata Build flags.
# These should be enabled by the platform if the erratum workaround needs to be
# applied.

# Flag to apply erratum 826319 workaround during reset. This erratum applies
# only to revision <= r0p2 of the Cortex A53 cpu.
ERRATA_A53_826319	?=0

# Flag to apply erratum 835769 workaround at compile and link time.  This
# erratum applies to revision <= r0p4 of the Cortex A53 cpu. Enabling this
# workaround can lead the linker to create "*.stub" sections.
ERRATA_A53_835769	?=0

# Flag to apply erratum 836870 workaround during reset. This erratum applies
# only to revision <= r0p3 of the Cortex A53 cpu. From r0p4 and onwards, this
# erratum workaround is enabled by default in hardware.
ERRATA_A53_836870	?=0

# Flag to apply erratum 843419 workaround at link time.
# This erratum applies to revision <= r0p4 of the Cortex A53 cpu. Enabling this
# workaround could lead the linker to emit "*.stub" sections which are 4kB
# aligned.
ERRATA_A53_843419	?=0

# Flag to apply errata 855873 during reset. This errata applies to all
# revisions of the Cortex A53 CPU, but this firmware workaround only works
# for revisions r0p3 and higher. Earlier revisions are taken care
# of by the rich OS.
ERRATA_A53_855873	?=0

# Flag to apply erratum 806969 workaround during reset. This erratum applies
# only to revision r0p0 of the Cortex A57 cpu.
ERRATA_A57_806969	?=0

# Flag to apply erratum 813419 workaround during reset. This erratum applies
# only to revision r0p0 of the Cortex A57 cpu.
ERRATA_A57_813419	?=0

# Flag to apply erratum 813420  workaround during reset. This erratum applies
# only to revision r0p0 of the Cortex A57 cpu.
ERRATA_A57_813420	?=0

# Flag to apply erratum 826974 workaround during reset. This erratum applies
# only to revision <= r1p1 of the Cortex A57 cpu.
ERRATA_A57_826974	?=0

# Flag to apply erratum 826977 workaround during reset. This erratum applies
# only to revision <= r1p1 of the Cortex A57 cpu.
ERRATA_A57_826977	?=0

# Flag to apply erratum 828024 workaround during reset. This erratum applies
# only to revision <= r1p1 of the Cortex A57 cpu.
ERRATA_A57_828024	?=0

# Flag to apply erratum 829520 workaround during reset. This erratum applies
# only to revision <= r1p2 of the Cortex A57 cpu.
ERRATA_A57_829520	?=0

# Flag to apply erratum 833471 workaround during reset. This erratum applies
# only to revision <= r1p2 of the Cortex A57 cpu.
ERRATA_A57_833471	?=0

# Flag to apply erratum 855972 workaround during reset. This erratum applies
# only to revision <= r1p3 of the Cortex A57 cpu.
ERRATA_A57_859972	?=0

# Flag to apply erratum 855971 workaround during reset. This erratum applies
# only to revision <= r0p3 of the Cortex A72 cpu.
ERRATA_A72_859971	?=0

# Flag to apply erratum 1592822 workaround during reset. This erratum applies
# on all Cortex A76 cpu.
ERRATA_A76_1592822	?=1

# Flag to apply erratum 1791580 workaround during reset. This erratum applies
# on all Cortex A77 cpu.
ERRATA_A77_1791580	?=1

# Flag to apply erratum 1946160 workaround during reset. This erratum applies
# on all Cortex A76 cpu.
ERRATA_A76_1946160	?=1

# Flag to apply T32 CLREX workaround during reset. This erratum applies
# only to r0p0 and r1p0 of the Ares cpu.
ERRATA_ARES_1043202	?=1

# Flag to apply DSU erratum 936184. This erratum applies to DSUs containing
# the ACP interface and revision < r2p0. Applying the workaround results in
# higher DSU power consumption on idle.
ERRATA_DSU_936184	?=0

# Flag to apply A75 erratum 1042767.
ERRATA_A75_1042767	?=1

# Process ERRATA_A53_826319 flag
$(eval $(call assert_boolean,ERRATA_A53_826319))
$(eval $(call add_define,ERRATA_A53_826319))

# Process ERRATA_A53_835769 flag
$(eval $(call assert_boolean,ERRATA_A53_835769))
$(eval $(call add_define,ERRATA_A53_835769))

# Process ERRATA_A53_836870 flag
$(eval $(call assert_boolean,ERRATA_A53_836870))
$(eval $(call add_define,ERRATA_A53_836870))

# Process ERRATA_A53_843419 flag
$(eval $(call assert_boolean,ERRATA_A53_843419))
$(eval $(call add_define,ERRATA_A53_843419))

# Process ERRATA_A53_855873 flag
$(eval $(call assert_boolean,ERRATA_A53_855873))
$(eval $(call add_define,ERRATA_A53_855873))

# Process ERRATA_A57_806969 flag
$(eval $(call assert_boolean,ERRATA_A57_806969))
$(eval $(call add_define,ERRATA_A57_806969))

# Process ERRATA_A57_813419 flag
$(eval $(call assert_boolean,ERRATA_A57_813419))
$(eval $(call add_define,ERRATA_A57_813419))

# Process ERRATA_A57_813420 flag
$(eval $(call assert_boolean,ERRATA_A57_813420))
$(eval $(call add_define,ERRATA_A57_813420))

# Process ERRATA_A57_826974 flag
$(eval $(call assert_boolean,ERRATA_A57_826974))
$(eval $(call add_define,ERRATA_A57_826974))

# Process ERRATA_A57_826977 flag
$(eval $(call assert_boolean,ERRATA_A57_826977))
$(eval $(call add_define,ERRATA_A57_826977))

# Process ERRATA_A57_828024 flag
$(eval $(call assert_boolean,ERRATA_A57_828024))
$(eval $(call add_define,ERRATA_A57_828024))

# Process ERRATA_A57_829520 flag
$(eval $(call assert_boolean,ERRATA_A57_829520))
$(eval $(call add_define,ERRATA_A57_829520))

# Process ERRATA_A57_833471 flag
$(eval $(call assert_boolean,ERRATA_A57_833471))
$(eval $(call add_define,ERRATA_A57_833471))

# Process ERRATA_A57_859972 flag
$(eval $(call assert_boolean,ERRATA_A57_859972))
$(eval $(call add_define,ERRATA_A57_859972))

# Process ERRATA_A72_859971 flag
$(eval $(call assert_boolean,ERRATA_A72_859971))
$(eval $(call add_define,ERRATA_A72_859971))

# Process ERRATA_A77_1791580 flag
$(eval $(call assert_boolean,ERRATA_A77_1791580))
$(eval $(call add_define,ERRATA_A77_1791580))

# Process ERRATA_ARES_1043202 flag
$(eval $(call assert_boolean,ERRATA_ARES_1043202))
$(eval $(call add_define,ERRATA_ARES_1043202))

# Process ERRATA_DSU_936184 flag
$(eval $(call assert_boolean,ERRATA_DSU_936184))
$(eval $(call add_define,ERRATA_DSU_936184))

# Process ERRATA_A76_1946160 flag
$(eval $(call assert_boolean,ERRATA_A76_1946160))
$(eval $(call add_define,ERRATA_A76_1946160))

# Process ERRATA_A75_1042767 flag
$(eval $(call assert_boolean,ERRATA_A75_1042767))
$(eval $(call add_define,ERRATA_A75_1042767))

# Process ERRATA_A76_1592822 flag
$(eval $(call assert_boolean,ERRATA_A76_1592822))
$(eval $(call add_define,ERRATA_A76_1592822))

# Errata build flags
ifneq (${ERRATA_A53_843419},0)
TF_LDFLAGS_aarch64	+= --fix-cortex-a53-843419
endif

ifneq (${ERRATA_A53_835769},0)
TF_CFLAGS_aarch64	+= -mfix-cortex-a53-835769
TF_LDFLAGS_aarch64	+= --fix-cortex-a53-835769
endif
