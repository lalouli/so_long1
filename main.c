/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:49:45 by hlalouli          #+#    #+#             */
/*   Updated: 2022/02/11 08:30:36 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include<stdio.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (check_extension(argv[1]) == 1)
			error_msg("name n'est pas existance\n", &data);
		create_map(argv[1], &data);
		variables_map(&data);
		check_map(&data);
		find_player(&data);
		init_window(&data);
		init_images(&data);
		render(&data);
		loop_images(data);
		destroy_images(data);
		free(data.mlx);
		if (data.map.map)
			ft_free(data.map.map);
		while (1)
			;
	}
}
