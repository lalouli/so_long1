/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:22:50 by hlalouli          #+#    #+#             */
/*   Updated: 2022/02/11 09:50:46 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../get_next_line/get_next_line.h"

int	check_extension(char *name_map)
{
	int	len;
	int	fd;

	len = 0;
	len = ft_strlen(name_map);
	fd = open(name_map, O_RDONLY);
	close(fd);
	if ((name_map[len - 3] == 'b' && name_map[len - 2] == 'e'
			&& name_map[len - 1] == 'r'
			&& name_map[len - 4] == '.'))
		return (0);
	return (1);
}

void	error_msg(char *str, t_data *data)
{
	if (data->map.map)
		ft_free(data->map.map);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	move_msg(t_data *data)
{
	ft_putstr("Moves counter : ");
	ft_putnbr(data->steps_count);
	ft_putchar('\n');
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}

void	variables_map(t_data *data)
{
	data->steps_count = 0;
	data->win_height = data->map.line_count * IMG_SIZE;
	data->win_width = (ft_strlen(data->map.map[0]) - 1) * IMG_SIZE;
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
}
