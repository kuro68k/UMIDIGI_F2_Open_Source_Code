#
# Copyright (c) 2014, ARM Limited and Contributors. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# Redistributions of source code must retain the above copyright notice, this
# list of conditions and the following disclaimer.
#
# Redistributions in binary form must reproduce the above copyright notice,
# this list of conditions and the following disclaimer in the documentation
# and/or other materials provided with the distribution.
#
# Neither the name of ARM nor the names of its contributors may be used
# to endorse or promote products derived from this software without specific
# prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

# CPU Errata Build flags. These should be enabled by the
# platform if the errata needs to be applied.

WORKAROUND_CVE_2018_3639	?=0

# Process WORKAROUND_CVE_2018_3639 flag
$(eval $(call assert_boolean,WORKAROUND_CVE_2018_3639))
$(eval $(call add_define,WORKAROUND_CVE_2018_3639))

# Flag to apply errata 826319 during reset. This errata applies only to
# revision <= r0p2 of the Cortex A53 cpu.
ERRATA_A53_826319	?=0

# Flag to apply errata 836870 during reset. This errata applies only to
# revision <= r0p3 of the Cortex A53 cpu. From r0p4 and onwards, this
# errata is enabled by default.
ERRATA_A53_836870	?=0

# Flag to apply errata 806969 during reset. This errata applies only to
# revision r0p0 of the Cortex A57 cpu.
ERRATA_A57_806969	?=0

# Flag to apply errata 813420 during reset. This errata applies only to
# revision r0p0 of the Cortex A57 cpu.
ERRATA_A57_813420	?=0

# Flag to apply workaround for CVE-2017-5715 issue.
WORKAROUND_CVE_2017_5715 ?=0

# Process ERRATA_A53_826319 flag
$(eval $(call assert_boolean,ERRATA_A53_826319))
$(eval $(call add_define,ERRATA_A53_826319))

# Process ERRATA_A53_836870 flag
$(eval $(call assert_boolean,ERRATA_A53_836870))
$(eval $(call add_define,ERRATA_A53_836870))

# Process ERRATA_A57_806969 flag
$(eval $(call assert_boolean,ERRATA_A57_806969))
$(eval $(call add_define,ERRATA_A57_806969))

# Process ERRATA_A57_813420 flag
$(eval $(call assert_boolean,ERRATA_A57_813420))
$(eval $(call add_define,ERRATA_A57_813420))

# Process WORKAROUND_CVE_2017_5715 flag
$(eval $(call assert_boolean,WORKAROUND_CVE_2017_5715))
$(eval $(call add_define,WORKAROUND_CVE_2017_5715))
