#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmdinfo.h"

static void usage(void);
static int cmdinfo(char *cmd);

int
main(int argc, char *argv[])
{
	int ret = 0;
	if (argc < 2) {
		fprintf(stderr, "cmdinfo: missing operand\n");
		fprintf(stderr, "Try 'cmdinfo --help' for more information\n");
		return 1;
	}

	if (!strcmp(argv[1], "--help") | !strcmp(argv[1], "-h"))
		usage();
	for (int i = 1; i < argc; i++) {
		if (cmdinfo(argv[i]) != 0)
			ret = 1;
	}

	return ret;
}

static int
cmdinfo(char *cmd)
{
	for (int i = 0; cmd_tbl[i].name; i++) {
		if (!strcmp(cmd_tbl[i].name, cmd)) {
			printf("Name: %s\n", cmd_tbl[i].name);
			printf("Version: %s\n", cmd_tbl[i].version);
			printf("Description: %s\n", cmd_tbl[i].desc);
			printf("Origin: %s\n", cmd_tbl[i].origin);
			printf("Status: %s\n", cmd_tbl[i].status);
			printf("Changes: %s\n", cmd_tbl[i].changes);
			return 0;
		}
	}

	return 1;
}

static void
usage(void)
{
	printf("usage: cmdinfo [--help|-h] <command>\n");
	exit(0);
}
