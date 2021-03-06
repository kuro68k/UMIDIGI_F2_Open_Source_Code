#ifndef _MTK_SCHED_H
#define _MTK_SCHED_H

#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <linux/ioctl.h>
#include <sched.h>
#include <linux/mt_sched_ioctl.h>

#ifdef __cplusplus
extern "C" {
#endif

int mt_sched_setaffinity(pid_t pid, size_t cpusetsize, cpu_set_t *mask);
int mt_sched_getaffinity(pid_t pid, size_t cpusetsize, cpu_set_t *mask, cpu_set_t *mt_mask);
int mt_sched_exitaffinity(pid_t pid);

int mt_sched_setvip(pid_t pid);
int mt_sched_unsetvip(pid_t pid);

#ifdef __cplusplus
}
#endif

#endif
