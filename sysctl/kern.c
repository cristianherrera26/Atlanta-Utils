#include <sys/utsname.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#if defined(__linux__)
#include "proc.h"
#endif

#define KERNELNAME	1
#define KERNELREL	2
#define KERNELVER	3
#define KERNELHOSTNAME	4

#define kernel_ostype		"/proc/sys/kernel/ostype"
#define kernel_osrelease	"/proc/sys/kernel/osrelease"

static struct utsname uts;

static int
get_uname(struct utsname uts, int info, char *buf, size_t buflen)
{
	if (uts.sysname[0] == '\0') {
		if (uname(&uts) != 0)
			return 1;
	}

	if (info == KERNELNAME)
		snprintf(buf, buflen, "%s", uts.sysname);
	else if (info == KERNELREL)
		snprintf(buf, buflen, "%s", uts.release);
	else if (info == KERNELVER)
		snprintf(buf, buflen, "%s", uts.version);
	else if (info == KERNELHOSTNAME)
		snprintf(buf, buflen, "%s", uts.nodename);
	return 0;
}

int
getostype(char *buf, size_t buflen)
{
#if defined(__linux__)
	if (read_proc(kernel_ostype, buf, buflen) == 0)
		return 0;
#endif
	return get_uname(uts, KERNELNAME, buf, buflen);
}
