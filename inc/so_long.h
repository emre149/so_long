/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:10:52 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/25 22:19:12 by ededemog         ###   ########.fr       */
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
# include "ft_printf/ft_printf.h"

/*MLX STRUCT*/

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*textures[5];
	//t_map		*map;
}	t_data;

#endif
