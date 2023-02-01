#include"utils.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

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
