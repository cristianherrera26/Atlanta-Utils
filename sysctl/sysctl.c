#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <getopt.h>
#include "sysctl.h"

static const struct option longopts[] = {
	{ "all", no_argument, 0, 'a' },
	{ "help", no_argument, 0, 'h'},
	{ 0, 0, 0, 0 }
};

#define ONLYVALUE	0x01

int sysctlbyname(const char *name);
static uint32_t flags;

int
main(int argc, char *argv[])
{
	int c, ret = 0;
	while ((c = getopt_long(argc, argv, "aAhn", longopts, NULL)) != -1) {
		switch (c) {
		case 'A':
		case 'a':
			break;
		case 'h':
			break;
		case 'n':
			flags |= ONLYVALUE;
			break;
		default:
			fprintf(stderr, "Try 'sysctl --help' for more information.\n");
			break;
		}
	}

	argc -= optind;
	argv += optind;

	for (int i = 0; i < argc; i++) {
		if (sysctlbyname(argv[i]) != 0)
			ret = 1;
	}

	return ret;
}

int
sysctlbyname(const char *name)
{
	char buf[128];
	for (int i = 0; sysctl_info[i].name; i++) {
		if (!strcmp(sysctl_info[i].name, name)) {
			if (!(flags & ONLYVALUE))
				printf("%s = ", name);
			if (sysctl_info[i].getinfo(buf, sizeof(buf)) != 0)
				return 1;
			printf("%s\n", buf);
			return 0;
		}
	}

	return 1;
}
