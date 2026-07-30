#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char ProductName[] = "AtlanticOS";
static const char ProductVersion[] = "26.0";		/* 26 => 2026 */ 
static const char ProductVersionExtra[] = "(b)";	/* AtlanticOS has 2 cycles, A (Jan-Jun) and B (Jul-Dec) */
#if defined(BUILD_VERSION)				/* This must be defined on official release builds */
static const char BuildVersion[] = BUILD_VERSION;
#else
static const char BuildVersion[] = __DATE__;
#endif

static void
usage(void)
{
	printf("usage: %s\n"
		"  or:  %s --productName\n"
		"  or:  %s --productVersion\n"
		"  or:  %s --productVersionExtra\n"
		"  or:  %s --buildVersion\n",
		getprogname(), getprogname(), getprogname(), getprogname(), getprogname());
	exit(1);
}

int
main(int argc, char *argv[])
{
	if (argc > 2)
		usage();
	if (argc == 2) {
		if (!strcmp(argv[1], "--productName") || !strcmp(argv[1], "-productName"))
			printf("%s\n", ProductName);
		else if (!strcmp(argv[1], "--productVersion") || !strcmp(argv[1], "-productVersion"))
			printf("%s\n", ProductVersion);
		else if (!strcmp(argv[1], "--productVersionExtra") || !strcmp(argv[1], "-productVersionExtra"))
			printf("%s\n", ProductVersionExtra);
		else if (!strcmp(argv[1], "--buildVersion") || !strcmp(argv[1], "-buildVersion"))
			printf("%s\n", BuildVersion);
		else
			usage();
	} else if (argc == 1) {
		printf( "ProductName:           %s\n"
			"ProductVersion:        %s\n"
			"ProductVersionExtra:   %s\n"
			"BuildVersion:          %s\n",
			ProductName, ProductVersion, ProductVersionExtra, BuildVersion);
	}

	return 0;
}
