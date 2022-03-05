/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 01:41:17 by hlalouli          #+#    #+#             */
/*   Updated: 2022/02/11 11:34:33 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-1);
	data->win = mlx_new_window(data->mlx, \
		(ft_strlen(data->map.map[0]) - 1) * IMG_SIZE, \
		data->map.line_count * IMG_SIZE, "SO_LONG");
	if (data->win == NULL)
	{
		free(data->win);
		return (-1);
	}
	return (0);
}

void	init_images(t_data *data)
{
	data->img.ground = mlx_xpm_file_to_image(data->mlx, "img/background.xpm",
			&data->img.width, &data->img.height);
	data->img.exit_l = mlx_xpm_file_to_image(data->mlx, "img/exit.xpm",
			&data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, "img/player.xpm",
			&data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm",
			&data->img.width, &data->img.height);
	data->img.coin1 = mlx_xpm_file_to_image(data->mlx, "img/coll.xpm",
			&data->img.width, &data->img.height);
}

void	loop_images(t_data data)
{
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, 2, 1L, &handle_keypress, &data);
	mlx_hook(data.win, 17, 1L, &handle_btnrealease, &data);
	mlx_loop(data.mlx);
}

void	destroy_images(t_data data)
{
	mlx_destroy_image(data.mlx, data.img.wall);
	mlx_destroy_image(data.mlx, data.img.ground);
	mlx_destroy_image(data.mlx, data.img.player);
	mlx_destroy_image(data.mlx, data.img.exit_l);
	mlx_destroy_image(data.mlx, data.img.coin1);
}
