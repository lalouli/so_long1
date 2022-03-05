/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:45:13 by hlalouli          #+#    #+#             */
/*   Updated: 2022/02/11 09:47:57 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char s)
{
	write(1, &s, 1);
	return ;
}

void	ft_putnbr(int nb)
{
	long int	n;

	n = nb;
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

void	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return ;
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 53)
	{
		exit(1);
	}
	else if (keysym == 0)
		move_player(data, keysym);
	else if (keysym == 1)
		move_player(data, keysym);
	else if (keysym == 2)
		move_player(data, keysym);
	else if (keysym == 13)
		move_player(data, keysym);
	return (0);
}

int	handle_btnrealease(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	return (0);
}
