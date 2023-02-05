/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pintables.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oburato <oburato@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:18:38 by oburato           #+#    #+#             */
/*   Updated: 2023/02/01 15:18:39 by oburato          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
