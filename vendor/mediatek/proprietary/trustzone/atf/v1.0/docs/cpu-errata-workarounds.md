ARM CPU Errata Workarounds
==========================

Security Vulnerability Workarounds
----------------------------------

-  ``WORKAROUND_CVE_2018_3639``: Enables the security workaround for
   `CVE-2018-3639`_. Defaults to 1. The TF-A project recommends to keep
   the default value of 1 even on platforms that are unaffected by
   CVE-2018-3639, in order to comply with the recommendation in the spec
   regarding workaround discovery.

ARM Trusted Firmware exports a series of build flags which control the
errata workarounds that are applied to each CPU by the reset handler. The
errata details can be found in the CPU specifc errata documents published
by ARM. The errata workarounds are implemented for a particular revision
or a set of processor revisions. This check is done in the debug build.
Each errata workaround is identified by its `ID` as specified in the processor's
errata notice document. The format of the define used to enable/disable the
errata is `ERRATA_<Processor name>_<ID>` where the `Processor name`
is either `A57` for the `Cortex_A57` CPU or `A53` for `Cortex_A53` CPU.

All workarounds are disabled by default. The platform is reponsible for
enabling these workarounds according to its requirement by defining the
errata workaround build flags in the platform specific makefile.

In the current implementation, a platform which has more than 1 variant
with different revisions of a processor has no runtime mechanism available
for it to specify which errata workarounds should be enabled or not.

The value of the build flags are 0 by default, that is, disabled. Any other
value will enable it.

For Cortex A53, following errata build flags are defined :

*   `ERRATA_A53_826319`: This applies errata 826319 workaround to Cortex-A53
     CPU. This needs to be enabled only for revision <= r0p2 of the CPU.

*   `ERRATA_A53_836870`: This applies errata 836870 workaround to Cortex-A53
     CPU. This needs to be enabled only for revision <= r0p3 of the CPU. From
     r0p4 and onwards, this errata is enabled by default.

For Cortex A57, following errata build flags are defined :

*   `ERRATA_A57_806969`: This applies errata 806969 workaround to cortex a57
     CPU. This needs to be enabled only for revision r0p0 of the CPU.

*   `ERRATA_A57_813420`: This applies errata 813420 workaround to cortex a57
     CPU. This needs to be enabled only for revision r0p0 of the CPU.

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

_Copyright (c) 2014, ARM Limited and Contributors. All rights reserved._
