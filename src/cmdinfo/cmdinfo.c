/*
 * NOTE: If you want to port this command to another system
 * you need to update or create the .about files so that it match
 * the origin and other details of each command.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <err.h>

#define INFO_PATH       "/usr/share/cmdinfo"

static void usage(void);
static int print_info(const char *cmd, const char *basepath);

int
main(int argc, char *argv[])
{
	int c, ret = 0;
	char *buf, *envpath;
	while ((c = getopt(argc, argv, "")) != -1) {
		switch (c) {
		default:
			usage();
		}
	}

	argc -= optind;
	argv += optind;

	if ((env_path = getenv("INFOPATH")) != NULL)
		buf = env_path;
	else
		buf = INFO_PATH;

	for (int i = 0; i < argc; i++) {
		if (print_info(argv[i], buf) != 0)
			ret = 1;
	}

	return ret;
}

static int
print_info(const char *cmd, const char *basepath)
{
	int ret_read = 0;
	char path[256], buf[512];
	snprintf(path, sizeof(path), "%s/%s.about", basepath);
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
