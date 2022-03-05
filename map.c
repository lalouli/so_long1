/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:18:39 by hlalouli          #+#    #+#             */
/*   Updated: 2022/02/11 09:35:31 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

void	line_num(char *line)
{
	int	j;

	j = 0;
	while (line[j] && line[j] != '\n')
	{
		if (!ft_strchr("01EPC", line[j++]))
		{	
			write(1, "Error\nInvalid Map4\n", 20);
			exit (1);
		}
	}
}

int	line_number(char *name_map)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(name_map, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error: open failed\n", 2);
		exit (1);
	}
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_num(line);
			line_count ++;
			free(line);
			line = NULL;
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

void	put_map(int row, int column, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->map.fd);
	while (line != NULL)
	{
		data->map.map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map.map[row])
			return ;
		while (line[i] != '\0')
			data->map.map[row][column++] = line[i++];
		data->map.map[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = NULL;
		line = get_next_line(data->map.fd);
	}
	data->map.map[row] = NULL;
}

void	create_map(char *name_map, t_data *data)
{
	int		row;
	int		i;
	int		column;

	i = 0;
	row = 0;
	column = 0;
	data->map.line_count = line_number(name_map);
	data->map.name_map = name_map;
	data->map.map = ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!(data->map.map))
		return ;
	data->map.fd = open(name_map, O_RDONLY);
	if (data->map.fd < 0)
		write(1, "Error: open failed\n", 20);
	else
	{
		put_map(row, column, i, data);
		close(data->map.fd);
	}
}
