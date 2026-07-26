/*
 * NOTE: If you want to port this command to another system
 * you need to update cmd_tbl so that it matches the origin
 * and other details of each command.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "cmdinfo.h"

static void usage(void);
static int cmdinfo(char *cmd);

static const struct option longopts[] = {
	{ "list", no_argument, 0, 'l' },
	{ "help", no_argument, 0, 'h' },
	{ 0, 0, 0, 0 },
};

int
main(int argc, char *argv[])
{
	int c, ret = 0;
	int list = 0;
	while ((c = getopt_long(argc, argv, "hl", longopts, NULL)) != -1) {
		switch (c) {
		case 'h':
			usage();
			break;
		case 'l':
			list = 1;
			break;
		default:
			fprintf(stderr, "Try 'cmdinfo --help' for more information\n");
			return 1;
		}
	}

	argc -= optind;
	argv += optind;

	if (list || argc == 0) {
		for (int i = 0; i < CMD_NUM; i++) {
			printf("%d. %s\n", i + 1, cmd_tbl[i].name);
		}
	} else {
		for (int i = 0; i < argc; i++) {
			if (cmdinfo(argv[i]) != 0)
				ret = 1;
		}
	}

	return ret;
}

static int
cmdinfo(char *cmd)
{
	for (int i = 0; i < CMD_NUM; i++) {
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

	fprintf(stderr, "cmdinfo: unknown command '%s'\n", cmd);
	return 1;
}

static void
usage(void)
{
	printf("usage: cmdinfo [--help|-h] [-l] [command]\n");
	exit(0);
}
