/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:10:52 by ededemog          #+#    #+#             */
/*   Updated: 2024/06/10 17:28:11 by ededemog         ###   ########.fr       */
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
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

/*MLX STRUCT*/

typedef struct	s_game {
	int		score;
	int		level;
}	t_game;

typedef struct s_player {
	int	x;
	int	y;
	int	health;
}	t_player;

typedef struct s_map {
	int		width;
	int		height;
	char	**layout
}	t_map;


typedef struct	s_sprite {
	void	*img;
	int		width;
	int		height;
}	t_sprite;

typedef struct	s_images {
	void	*wall;
	int		wall_width;
	int		wall_height;

	void	*floor;
	int		floor_width;
	int		floor_height;

	void	*collectible;
	int		collectible_width;
	int		collectible_height;
	
	void	*exit;
	int		exit_width;
	int		exit_height;

	void	*position;
	int		position_width;
	int		position_height;
}	t_images;

char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strcpy(char *dest, char *src);

int	*read_dimension(const char *file);
void read_lines(int width, int height, const char *file);


#endif
