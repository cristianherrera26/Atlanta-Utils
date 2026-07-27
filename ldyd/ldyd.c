#include <sys/types.h>
#include <sys/param.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <err.h>

#if defined(__linux__) && (defined(__x86_64__) || defined(__amd64__))
 #if defined(__atlantic__)			/* Dynamic Loader name in AtlanticOS (Uses a musl fork)*/
 #define LD	"/usr/libexec/ld_elf.so.1"
 #elif !defined(__GLIBC__)			/* musl */
 #define LD	"/lib/ld-musl-x86_64.so.1"
 #endif 					/* We dont need the dynamic loader name for GLIBC */
#else
 #error "This only works properly on x86_64 Linux"	/* We only care about Linux on x86_64 machines */
#endif

static void usage(void);
static int ldyd_main(char *file);
static int is_script(char *file);

static const struct option longopts[] = {
	{ "help", no_argument, 0, 'h' },
	{ 0, 0, 0, 0 }
};

int
main(int argc, char *argv[])
{
	int c, ret = 0;
	setprogname(argv[0]);

	while ((c = getopt_long(argc, argv, "h", longopts, NULL)) != -1) {
		switch (c) {
		case 'h':
			usage();
			break;
		default:
			fprintf(stderr, "Try '%s --help' for more information.\n", getprogname());
			return 1;
		}
	}

	argc -= optind;
	argv += optind;

	if (argc == 0) {
		fprintf(stderr, "%s: missing operand\n", getprogname());
		fprintf(stderr, "Try '%s --help' for more information.\n", getprogname());
		return 1;
	}

	for (int i = 0; i < argc; i++) {
		if (argc > 1) {
			printf("%s:\n", argv[i]);
		}

		if (ldyd_main(argv[i]) != 0)
			ret = 1;
	}

	return ret;
}

static int
ldyd_main(char *file)
{
	char buf[PATH_MAX];
	if (!strrchr(file, '/')) {
		snprintf(buf, sizeof(buf), "./%s", file);
	} else {
		snprintf(buf, sizeof(buf), "%s", file);
	}

	if (access(buf, F_OK) != 0) {
		fprintf(stderr, "%s: %s: No such file or directory\n", getprogname(), buf);
		return 1;
	}

	if (access(buf, X_OK) != 0) {
		fprintf(stderr, "%s: warning: you do not have execution permission for '%s'\n", getprogname(), buf);
		goto no_exec;
	}

	if (is_script(buf)) {
		goto no_exec;
	}

#if defined(__GLIBC__)
	setenv("LD_TRACE_LOADED_OBJECTS", "1", 1);
#endif
	pid_t pid = fork();
	if (pid == -1) {
		err(EXIT_FAILURE, "fork");
	}

	if (pid == 0) {
#if defined(__GLIBC__)
		if (execl(buf, buf, NULL) != 0) {
			err(EXIT_FAILURE, "%s", buf);
#else
		if (execl(LD, LD, "--list", buf, NULL) != 0) {
			err(EXIT_FAILURE, "%s", LD);
#endif
		}
	}

	waitpid(pid, NULL, 0);	/* I don't care about the exit code */
	goto end;

no_exec:
	fprintf(stderr, "\tnot a dynamic executable\n");
	return 1;

end:
	return 0;
}

static int
is_script(char *file)
{
	int fd;
	char buf[2];
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return 0;
	if (read(fd, buf, 2) != 2) {
		close(fd);
		return 0;
	}

	close(fd);

	if (buf[0] == '#' && buf[1] == '!')
		return 1;

	return 0;
}

static void
usage(void)
{
	printf("usage: %s [--help|-h] FILE...\n", getprogname());
	exit(0);
}
