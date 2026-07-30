/*
 * NOTE: If you want to port this command to another system
 * you need to update or create the .about files so that it match
 * the origin and other details of each command.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <fcntl.h>
#include <err.h>

#define INFO_PATH       "/usr/share/cmdinfo"

static void usage(void);
static int print_info(char *cmd);

static const struct option longopts[] = {
	{ "list", no_argument, 0, 'l' },
	{ "help", no_argument, 0, 'h' },
	{ 0, 0, 0, 0 },
};

int
main(int argc, char *argv[])
{
	int c, ret = 0;
	while ((c = getopt(argc, argv, "")) != -1) {
		switch (c) {
		default:
			usage();
		}
	}

	argc -= optind;
	argv += optind;

	for (int i = 0; i < argc; i++) {
		if (print_info(argv[i]) != 0)
			ret = 1;
	}

	return ret;
}

static int
print_info(char *cmd)
{
	int ret_read = 0;
	char path[256], buf[512];
	char *env_path = getenv("INFOPATH");
	if (env_path)
		snprintf(path, sizeof(path), "%s/%s.about", env_path, cmd);
	else
		snprintf(path, sizeof(path), "%s/%s.about", INFO_PATH, cmd);
	int fd = open(path, O_RDONLY);
	if (fd < 0) {
		warn("%s", path);
		return 1;
	}

	ret_read = read(fd, buf, sizeof(buf));
	if (ret_read < 0)
		return 1;
	write(STDOUT_FILENO, buf, ret_read);
	return 0;
}

static void
usage(void)
{
	printf("usage: cmdinfo COMMAND\n");
	exit(1);
}
