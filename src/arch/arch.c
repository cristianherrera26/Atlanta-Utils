#include <sys/param.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

static void usage(void);

int
main(int argc, char *argv[])
{
	int c;
	char *print = NULL;
	while ((c = getopt(argc, argv, "k")) != -1) {
		switch (c) {
		case 'k':
			print = MACHINE_ARCH;
			break;
		default:
			usage();
		}
	}

	argc -= optind;
	argv += optind;

	if (print == NULL)
		print = MACHINE;

	if (argc != 0 && argc != 1)
		usage();

	if (argc == 0) {
		puts(print);
	} else {
		if (strcmp(argv[0], print))
			return 1;
	}

	return 0;
}

static void
usage(void)
{
	fprintf(stderr, "usage: arch [-k] [archname]\n");
	exit(1);
}
