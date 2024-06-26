/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:10:52 by ededemog          #+#    #+#             */
/*   Updated: 2024/06/26 15:17:58 by ededemog         ###   ########.fr       */
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

/*MLX STRUCT*/

typedef enum	e_tiles
{
	EMPTY,
	WALL,
	COLLECTABLES,
	EXIT,
	PLAYER
}	t_tiles;

typedef struct s_position
{
	int		x;
	int		y;
}	t_position;

typedef struct s_map
{
	int		width;
	int		height;
	int		num_collectables;
	t_tiles **tiles;
	t_position	player_pos;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			w_width;
	int			w_height;
	int			i_width;
	int			i_height;
	void		*img;
	void		*textures[5];
	t_map		*map;
}	t_data;

char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strcpy(char *dest, char *src);

int	*read_dimension(const char *file);
void read_lines(int width, int height, const char *file);


#endif
