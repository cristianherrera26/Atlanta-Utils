#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char ProductName[] = "AtlanticOS";
static const char ProductVersion[] = "26B";
#if defined(BUILD_VERSION)
static const char BuildVersion[] = BUILD_VERSION;
#else
static const char BuildVersion[] = __DATE__;
#endif

static void
usage(void)
{
	printf("usage: %s\n"
		"  or:  %s -productName\n"
		"  or:  %s -productVersion\n"
		"  or:  %s -buildVersion\n",
		getprogname(), getprogname(), getprogname(), getprogname());
	exit(0);
}

int
main(int argc, char *argv[])
{
	if (argc > 1) {
		if (!strcmp(argv[1], "-productName"))
			printf("%s\n", ProductName);
		else if (!strcmp(argv[1], "-productVersion"))
			printf("%s\n", ProductVersion);
		else if (!strcmp(argv[1], "-buildVersion"))
			printf("%s\n", BuildVersion);
		else if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h"))
			usage();
		else {
			fprintf(stderr, "%s: invalid option '%s'\n", getprogname(), argv[1]);
			return 1;
		}
	} else {
		printf("ProductName: %s\nProductVersion: %s\nBuildVersion: %s\n",
			ProductName, ProductVersion, BuildVersion);
	}

	return 0;
}
