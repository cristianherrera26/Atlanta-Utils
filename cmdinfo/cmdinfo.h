#ifndef CMDINFO_H
#define CMDINFO_H	1

/* The first letter must be a Capital letter */
/* Why? It's my rule */

typedef struct {
	const char *name;		/* Command Name */ 	  /* e.g: uname */
	const char *version;		/* Command Version */	  /* e.g: 1.0 */
	const char *desc;		/* Command Description */ /* e.g: Print system information */
	const char *origin;		/* Command Origin */	  /* e.g: NetBSD */
	const char *status;		/* Command Status */	  /* e.g: Stable */
	const char *changes;		/* Command Changes */	  /* e.g: Remove sysctl dependency */
} table_t;

/* The command version increment with each important modification */
/* To the original file, e.g: add a new option or fix a bug */

/* In this table there are commands from others repositories */
/* Like Core-Utils, may you need to check it to update this table */

/* This table is in alphabetical order */
static const table_t cmd_tbl[] = {
	{ "bsdvers", "1.0", "Print project information", "AtlanticOS", "Stable", "None" },
	{ "echo", "1.0", "Display all passed arguments to standard output", "NetBSD", "Stable", "None" },
	{ "hostname", "1.0", "Print or set the system hostname", "NetBSD", "Stable", "None" },
	{ "ldyd", "1.0", "List the dynamic dependencies of a executable", "AtlanticOS", "Stable", "None" },
	{ "pwd", "1.0", "Print the current working directory", "NetBSD", "Stable", "None" },
	{ "sw_vers", "1.0", "A reimplementation of the macOS command", "AtlanticOS", "Stable", "None" },
	{ "uname", "1.0", "Print system information", "NetBSD", "Stable", "Replace sysctl uses with MACHINE_ARCH macro" },
	{ "cmdinfo", "1.0", "Print information about a command", "AtlanticOS", "Stable", "None" },
};

#define CMD_NUM	8	/* This is unused, is only for know commands number */

#endif
