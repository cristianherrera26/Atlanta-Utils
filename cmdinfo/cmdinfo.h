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
	{ "basename", "1.0", "Print the file name portion of the given path(s)", "NetBSD", "Stable", "None" },
	{ "bsdvers", "1.0", "Print project information", "AtlanticOS", "Stable", "None" },
	{ "cmdinfo", "1.0", "Print information about a command", "AtlanticOS", "Unfinished", "None" },
	{ "dirname", "1.0", "Print the directory portion of the given path(s)", "NetBSD", "Stable", "None" },
	{ "domainname", "1.0", "Print or set the NIS/YP domain name", "NetBSD", "Stable", "None" },
	{ "echo", "1.0", "Display all passed arguments to standard output", "NetBSD", "Stable", "None" },
	{ "env", "1.0", "Print or modify the environment variables", "NetBSD", "Stable", "None" },
	{ "false", "1.0", "Return an unsucessful exit code", "OpenBSD", "Stable", "None" },
	{ "groups", "1.0", "Show groups memberships", "NetBSD", "Stable", "None" },
	{ "hostname", "1.0", "Print or set the system hostname", "NetBSD", "Stable", "None" },
	{ "id", "1.0", "return user identifiy", "NetBSD", "Stable", "None" },
	{ "ldyd", "1.0", "List the dynamic dependencies of an executable", "AtlanticOS", "Stable", "None" },
	{ "link", "1.0", "Create a hardlink file2 pointing to file1", "NetBSD", "Stable", "None" },
	{ "ln", "1.0", "Create symlinks and hardlinks", "NetBSD", "Stable", "None" },
	{ "printenv", "1.0", "Print the environment variables", "NetBSD", "Stable", "None"},
	{ "pwd", "1.0", "Print the current working directory", "NetBSD", "Stable", "None" },
	{ "sw_vers", "1.1", "A reimplementation of the macOS command", "AtlanticOS", "Stable", "Update command for compatibility"
										               " with modern macOS" },
	{ "sync", "1.0", "Call to the sync syscall", "NetBSD", "Stable", "None" },
	{ "tee", "1.0", "Copy standard input to each FILE, and also to standard output.", "NetBSD", "Stable", "None" },
	{ "touch", "1.0", "Change file access and modification times", "NetBSD", "Stable", "None" },
	{ "true", "1.0", "Return a sucessful exit code", "OpenBSD", "Stable", "None" },
	{ "tty", "1.0", "Print the file name terminal connected to the standard input", "NetBSD", "Stable", "None" },
	{ "uname", "1.2", "Print system information", "NetBSD", "Stable",  "\n- Remove sysctl dependency"
									   "\n- Add -o option to print os name"
									   "\n- Add -i option to print hardware platform"
									   "\n- Update man page" },
	{ "unlink", "1.0", "Remove a file using the unlink syscall", "NetBSD", "Stable", "None" },
	{ "whoami", "1.0", "Print the current user name", "NetBSD", "Stable", "None" }
};

#define CMD_NUM	25 /* If you add or remove a command, you must update this number */

#endif
