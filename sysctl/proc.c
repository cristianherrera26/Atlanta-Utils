#if defined(__linux__)
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int
read_proc(const char *path, char *buf, size_t buflen)
{
	int ret = 0;
	char *str;
	int fd = open(path, O_RDONLY);
	if (fd < 0) return 1;
	ret = read(fd, buf, buflen - 1);
	if (ret < 0)
		return 1;
	if ((str = strchr(buf, '\n')) != NULL)
		*str = '\0';
	return 0;
}
#endif
