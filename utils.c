/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:52:32 by hlalouli          #+#    #+#             */
/*   Updated: 2022/02/11 09:44:13 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	if (!res)
	{
		perror("Error");
		exit(1);
	}
	ft_bzero(res, size * count);
	return (res);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*res;

	res = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		res[i] = (unsigned char) c;
		i++;
	}	
	return (res);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}
