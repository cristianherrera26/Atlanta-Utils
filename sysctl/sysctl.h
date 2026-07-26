#ifndef _SYSCTL_H
#define _SYSCTL_H	1

#include "kern.h"

typedef struct {
	const char *name;
	const char *category;
	int (*getinfo)(char *buf, size_t buflen);
} sysctl_t;

static const sysctl_t sysctl_info[] = {
	{ "kern.ostype", "kern", getostype },
	{ NULL, NULL, NULL }
};

#endif
