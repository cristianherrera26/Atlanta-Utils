#include <stdio.h>

#define RESET  "\x1B[0m"
#define ORANGE "\x1B[38;5;208m"
#define URL "https://github.com/cristianherrera26/Atlanta-Utils"

int
main(void)
{
	printf("\n");
	printf("   \\\\ %s`-______,----__%s           Atlanta-Utils v26\n", ORANGE, RESET);
	printf("    \\\\       %s __,---`_%s          Copyright (c) 2026 AtlanticOS Team\n", ORANGE, RESET);
	printf("     \\\\      %s `.____%s            Copyright (c) 2026 Cristian Herrera\n", ORANGE, RESET);
	printf("      \\\\ %s-______,----`-%s         Homepage: " URL "\n", ORANGE, RESET);
	printf("       \\\\                       \n");
	printf("        \\\\                      \n");
	printf("         \\\\                     This set of programs may be freely redistributed under\n");
	printf("          \\\\                    The terms of the BSD 3-Clause License.\n");
	return 0;
}
