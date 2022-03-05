/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:11:55 by hlalouli          #+#    #+#             */
/*   Updated: 2022/02/06 14:35:19 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../get_next_line/get_next_line.h"

int	check_map_format(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->map.line_len = ft_strlen(data->map.map[i]) - 1;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
			j++;
		if (j != data->map.line_len)
			return (1);
		i++;
	}
	if (data->map.map[--i][j] == '\n')
		return (1);
	return (0);
}

int	check_lines(int ligne, char **map)
{
	int	i;

	i = 0;
	while (map[ligne][i] && map[ligne][i] != '\n')
	{
		if (map[ligne][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_lines_d_f(int line_count, char **map)
{
	int	i;

	i = 1;
	if (check_lines(0, map) == 1 || check_lines(line_count, map) == 1)
		return (1);
	while (i < line_count)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_p_c_e(t_data *data)
{
	data->map.num_p = 0;
	data->map.num_c = 0;
	data->map.num_e = 0;
	data->x = 0;
	while (data->map.map[data->x])
	{
		data->y = 0;
		while (data->map.map[data->x][data->y])
		{
			if (data->map.map[data->x][data->y] == 'P')
				data->map.num_p++;
			else if (data->map.map[data->x][data->y] == 'E')
					data->map.num_e++;
			else if (data->map.map[data->x][data->y] == 'C')
				data->map.num_c++;
			data->y++;
		}
		data->x++;
	}
	if (!data->map.num_p || !data->map.num_c || !data->map.num_e)
		return (1);
	else
		return (0);
}

int	check_map(t_data *data)
{
	if (check_p_c_e(data) == 1)
		error_msg("Invalide map\n", data);
	if (data->map.num_p > 1)
		error_msg("Invalide map1\n", data);
	if (check_map_format(data) == 1)
		error_msg("Invalide map2\n", data);
	if (check_lines_d_f(data->map.line_count - 1, data->map.map) == 1)
		error_msg("Invalide map3\n", data);
	return (0);
}
