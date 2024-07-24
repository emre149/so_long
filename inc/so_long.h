/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:40:11 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/24 14:01:38 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define INTMAX 2147483647
# define INTMIN -2147483648

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define HEIGHT 32
# define WIDTH 32

# define WALL '1'
# define EMPTY '0'
# define COLLECTABLE 'C'
# define PLAYER 'P'
# define EXIT 'E'

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_Q 113
# define KEY_ESC 65307

# define PLAYER_X "assets/player.xpm"
# define EXIT_X "assets/hole.xpm"
# define COLLECTABLE_X "assets/item.xpm"
# define WALL_X "assets/wall.xpm"
# define EMPTY_X "assets/water.xpm"

typedef struct s_main
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		line_len;
	int		col_len;
	int		start_i;
	int		start_j;
	int		current_i;
	int		current_j;
	int		item_nbr;
	int		item_found;
	bool	exit_found;
	void	*player;
	void	*exit;
	void	*collectables;
	void	*wall;
	void	*empty;
	int		height;
	int		width;
	int		total_moves;
}			t_main;

// PARSING

void 		store_map(t_main *win, char **argv);
void		check_argv(t_main *win, char **argv);
void		check_inputs(t_main *win);
void		exit_check(t_main *win);
void		collectable_check(t_main *win);
void		start_check(t_main *win);
void		rectangle_check(t_main *win);
void		closed_check(t_main *win);
void 		is_map_valid(t_main *win, char **map_cpy, int i, int j);
int			ft_tab_len(char **tab);




// void		store_map(t_main *so_long, char **argv);
// void		check_inputs(t_main *so_long);
// void		check_argv(t_main *so_long, char **argv);
// void		check_map_rectangle(t_main *so_long);
// void		check_map_exit(t_main *so_long);
// void		check_map_item(t_main *so_long);
// void		check_map_start(t_main *so_long);
// void		check_map_closed(t_main *so_long);
// void		check_map_valid(t_main *so_long, char **map_cpy, int i, int y);

// MLX

void		win_init(t_main *win);
void		load_images(t_main *win);
void		img_display(t_main *win, void *img_ptr, int i, int j);
void		win_display(t_main *win);
int			handle_moves(t_main *win, int key, int i, int j);
int			handle_close(t_main *win);
int			move_to(t_main *win, int i, int j);


// void		win_init(t_main *so_long);
// void		load_imgs(t_main *so_long);
// void		win_show_map(t_main *so_long);
// int			handle_moves(t_main *so_long, int key, int i, int j);
// void		print_img(t_main *so_long, void *img_ptr, int i, int j);
// int			move_to(t_main *win, int i, int j);

// MLX UTILS


int 		handle_keypress(int keysym, t_main *win);
void		mlx_destroy_imgs(t_main *so_long);

// FREE UTILS

void		free_all(t_main *win);
void		free_errors(t_main *win, char *err_msg);
void		free_all_and_errors(t_main *win, char *err_msg);
void		malloc_exit(t_main *win);
void		mlx_exit(t_main *win);
void		handle_error(t_main *win, char *err_msg, int err_code);
void		mlx_destroy_imgs(t_main *so_long);

// void		free_all(t_main *so_long);
// void		free_all_and_error(t_main *so_long, char *error);
// void		malloc_exit(t_main *so_long);
// void		mlx_exit(t_main *so_long);

#endif