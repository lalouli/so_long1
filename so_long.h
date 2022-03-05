/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:21:37 by hlalouli          #+#    #+#             */
/*   Updated: 2022/02/11 09:48:52 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include<mlx.h>
# include<fcntl.h>
# include "../get_next_line/get_next_line.h"

# define IMG_SIZE 48
# define A 0
# define D 2
# define S 1
# define W 13

typedef struct s_map
{
	int		fd;
	int		line_count;
	int		line_len;
	int		num_p;
	int		num_e;
	int		num_c;
	char	**map;
	char	*name_map;
	int		can_exit;
	int		collected;

}				t_map;

typedef struct s_img
{
	void	*mlx_img;
	int		width;
	int		height;
	void	*wall;
	void	*exit_l;
	void	*ground;
	void	*player;
	int		line_length;
	void	*coin1;

}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		steps_count;
	int		p_i;
	int		p_j;
	int		x;
	int		y;
	int		win_height;
	int		win_width;
	t_img	img;
	t_map	map;

}				t_data;

# define IMG_SIZE 48

int		check_p_c_e(t_data *data);
int		check_lines(int ligne, char **map);
int		check_lines_d_f(int line_count, char **map);
int		check_map_format(t_data *data);
void	error_msg(char *str, t_data *data);
int		check_map(t_data *data);
int		check_extension(char *path);
void	ft_free(char **tab);
void	line_num(char *line);
int		line_number(char *name_map);
void	put_map(int row, int column, int i, t_data *data);
void	create_map(char *name_map, t_data *data);
void	find_player(t_data *data);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strchr(const char *s, int c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	variables_map(t_data *data);
void	parse_chars(t_data *data, int width, int i, int j);
int		render(t_data *data);
int		init_window(t_data *data);
void	init_images(t_data *data);
void	loop_images(t_data data);
void	destroy_images(t_data data);
void	move_msg(t_data *data);
int		check_next_tile(t_data *data, char direction, char tile);
void	collect_coins(t_data *data, char direction);
void	win_game(t_data *data);
void	move_player(t_data *data, char direction);
int		handle_keypress(int keysym, t_data *data);
int		handle_btnrealease(t_data *data);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);
void	ft_putchar(char s);

#endif
