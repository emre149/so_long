/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:40:11 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/25 15:32:50 by ededemog         ###   ########.fr       */
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

# define HEIGHT 96
# define WIDTH 96

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

typedef struct s_assets
{
	void	*bg_2_1;
	void	*bg_2_2;
	void	*bg_2_3;
	void	*bg_1;
	void	*chest_o;
	void	*chest;
	void	*exit;
	void	*player;
	void	*wall_bl;
	void	*wall_br;
	void	*wall_tl;
	void	*wall_tr;
	void	*wall_t;
	void	*wall_b;
	void	*wall_l;
	void	*wall_r;
	void	*wall;
}				t_assets;

typedef struct s_main {
	void		*mlx;
	void		*mlx_win;
	int			game_state;
	char		*map;
	int			map_w;
	int			map_h;
	int			move;
	int			collect;
	int			player_pos;
	t_assets	assets;
}				t_main;

// ------------------------------------------------------ check_solvability.c --

char	*spread(char *mapcpy, int pos, int *nb_to_find);
int		check_map_can_be_solved(char *map, t_main *game);

// ------------------------------------------------------------------ check.c --

int		check_enclosure(char *map);
int		check_charactere(char *map);
int		check_integrity(char *map);
int		check_map(t_main *game, char *filename);

// ------------------------------------------------------------------- imgs.c --

int		open_imgs(void *mlx, t_main *game);
int		close_img(t_main *g);
int		close_img_wall(t_main *g);

// ------------------------------------------------------------- maps_funct.c --

int		get_map_size(t_main *game, char *filename);
int		get_map(t_main *game, char *file);

// ------------------------------------------------------------------- move.c --

int		move_check(t_main *game, char direction);
int		move_player(t_main game, int from_pos, char direction);

// ----------------------------------------------------------------- render.c --

int		img_display(t_main win, char c, int x, int y);
int		fill_win(t_main win);
void	*get_wall(t_main win, int x, int y);

// ---------------------------------------------------------------- so_long.c --

int		clean_exit(t_main *win);
int		key_handler(int keycode, t_main *win);
void	event_listener(t_main *win);

// ------------------------------------------------------------------ utils.c --

int		item_occ(char *str, char c);
int		line_len(char *str);
int		get_ind(int pos, char *map, char directions);
int		index(char *map, char tf);
int		find_x_y(t_main win, int pos, int *x, int *y);

#endif