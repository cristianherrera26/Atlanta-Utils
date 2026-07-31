#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void usage(void);

int
main(int argc, char *argv[])
{
	int c;
	while ((c = getopt(argc, argv, "")) != -1) {
		switch (c) {
		default:
			usage();
		}
	}

	if (argc != optind)
		usage();

	printf("%lx\n", gethostid() & 0xFFFFFFFF);
	return 0;
}

static void
usage(void)
{
	fprintf(stderr, "usage: hostid\n");
	exit(1);
}
