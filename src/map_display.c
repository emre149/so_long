/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:09:11 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/24 14:20:31 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_images(t_main *win)
{
	win->width = 32;
	win->height = 32;
	win->player = mlx_xpm_file_to_image(win->mlx_ptr, PLAYER_X,
			&win->width, &win->height);
	win->exit = mlx_xpm_file_to_image(win->mlx_ptr, EMPTY_X,
			&win->width, &win->height);
	win->collectables = mlx_xpm_file_to_image(win->mlx_ptr, COLLECTABLE_X,
			&win->width, &win->height);
	win->wall = mlx_xpm_file_to_image(win->mlx_ptr, WALL_X,
			&win->width, &win->height);
	win->empty = mlx_xpm_file_to_image(win->mlx_ptr, EMPTY_X,
			&win->width, &win->height);
	if (!win->player || !win->exit || !win->collectables || !win->wall || !win->empty)
		free_all_and_errors(win, "Error\nXPM to IMG failed\n");
}

void	img_display(t_main *win, void *img_ptr, int i, int j)
{
	int	i_pos;
	int	j_pos;

	i_pos = j * 32;
	j_pos = i * 32;
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img_ptr, j_pos, i_pos);
}

void	win_display(t_main *win)
{
	int	i;
	int	j;

	i = 0;
	load_images(win);
	while (win->map[i])
	{
		j = 0;
		while (win->map[i][j])
		{
			if (win->map[i][j] == WALL)
				(img_display(win, win->wall, j, i), img_display(win, win->wall, j, i));
			else if (win->map[i][j] == EMPTY)
				img_display(win, win->empty, j, i);
			else if (win->map[i][j] == PLAYER)
				img_display(win, win->player, j, i);
			else if (win->map[i][j] == COLLECTABLE)
				img_display(win, win->collectables, j, i);
			else if (win->map[i][j] == EXIT)
				img_display(win, win->exit, j, i);
			j++;
		}
		i++;
	}
}