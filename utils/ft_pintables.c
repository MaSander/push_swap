#include"utils.h"

size_t	ft_putstr_fd(char *s, int fd)
{
	if (s)
		return (write(fd, s, ft_strlen(s)));
	return (0);
}

size_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
