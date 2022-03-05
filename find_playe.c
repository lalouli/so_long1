/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_playe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:33:27 by hlalouli          #+#    #+#             */
/*   Updated: 2022/02/11 09:33:59 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->p_i = i;
				data->p_j = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	check_next_tile(t_data *data, char direction, char tile)
{
	if ((direction == 2 && data->map.map[data->p_i][data->p_j + 1] == tile)
		|| (direction == 0 && data->map.map[data->p_i][data->p_j - 1] == tile)
		|| (direction == 1 && data->map.map[data->p_i + 1][data->p_j] == tile)
		|| (direction == 13 && data->map.map[data->p_i - 1][data->p_j] == tile)
		)
		return (0);
	else
		return (1);
}

void	collect_coins(t_data *data, char direction)
{
	if ((direction == 2 && data->map.map[data->p_i][data->p_j + 1] == 'C')
		|| (direction == 0 && data->map.map[data->p_i][data->p_j - 1] == 'C')
		|| (direction == 1 && data->map.map[data->p_i + 1][data->p_j] == 'C')
		|| (direction == 13 && data->map.map[data->p_i - 1][data->p_j] == 'C'))
		data->map.collected++;
}

void	win_game(t_data *data)
{
	if (data->map.can_exit == 1)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		write(1, "you win\n", 9);
		exit(1);
	}
}

void	move_player(t_data *data, char direction)
{
	if (check_next_tile(data, direction, '1') == 0
		|| (data->map.can_exit == 0
			&& check_next_tile(data, direction, 'E') == 0))
		return ;
	data->steps_count++;
	collect_coins(data, direction);
	if (data->map.collected == data->map.num_c)
		data->map.can_exit = 1;
	data->map.map[data->p_i][data->p_j] = '0';
	if (direction == 2)
		data->p_j++;
	else if (direction == 0)
		data->p_j--;
	else if (direction == 1)
		data->p_i++;
	else if (direction == 13)
		data->p_i--;
	move_msg(data);
	if (data->map.can_exit == 1 && data->map.map[data->p_i][data->p_j] == 'E')
		win_game(data);
	data->map.map[data->p_i][data->p_j] = 'P';
}
