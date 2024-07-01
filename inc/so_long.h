/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:10:52 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/01 15:01:03 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*INCLUDES*/

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/types.h>
# include <stddef.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "ft_printf/ft_printf.h"
//# include "get_next_line/get_next_line.h"

// ASSETS SIZE
# define HEIGHT 32
# define WIDTH 32

// MAP COMPONENTS
# define WALL '1'
# define WATER '0'
# define ITEM 'C'
# define PLAYER 'P'
# define EXIT 'E'

// WASD
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

// ARROWS
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

// EXIT
# define KEY_Q 113
# define KEY_ESC 65307

# define PLAYER "assets/player.xpm"
# define HOLE "assets/hole.xpm"
# define ITEM "assets/item.xpm"
# define WALL "assets/wall.xpm"
# define WATER "assets/water.xpm"

/*MLX STRUCT*/
typedef struct	s_main
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			lines;
	int			cols;
	int			start_i;
	int			start_j;
	int			actual_i;
	int			actual_j;
	int			items_nbr;
	int			items_collected;
	void		*player;
	void		*empty;
	void		*collectables;
	void		*wall;
	void		*exit;
	bool		exit_found;
}				t_main;

char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strcpy(char *dest, char *src);

int	*read_dimension(const char *file);
void read_lines(int width, int height, const char *file);


#endif
