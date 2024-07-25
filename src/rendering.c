/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:28:42 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/24 16:39:43 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	img_display(t_main win, char c, int x, int y)
{
	void	*img;

	img = win.assets.bg_1;
	if (c == PLAYER)
		img = get_wall(win, x, y);
	if (c == EMPTY)
		img = win.assets.bg_1;
	if (c == COLLECTABLE)
		img = win.assets.chest;
	if (c == 'O')
		img = win.assets.chest_o;
	if (c == PLAYER)
		img = win.assets.player;
	if (c == EXIT)
		img = win.assets.exit;
	mlx_put_image_to_window(win.mlx, win.mlx_win, img, x , y);
	return (0);
}

void	*get_wall(t_main win, int x, int y)
{
	void	*img;

	img = win.assets.wall;
	if (y / 96 == 0)
		img = win.assets.wall_t;
	if (y / 96 == win.map_h - 1)
		img = win.assets.wall_b;
	if (x / 96 == 0)
		img = win.assets.wall_l;
	if (x / 96 == (win.map_w - 1))
		img = win.assets.wall_r;
	if (x / 96 == 0 && y / 96 == 0)
		img = win.assets.wall_tl;
	if (x / 96 == (win.map_w - 1) && y / 96 == 0)
		img = win.assets.wall_tr;
	if (x / 96 == 0 && y / 96 == win.map_h - 1)
		img = win.assets.wall_bl;
	if (x / 96 == (win.map_w - 1) && y / 96 == win.map_h - 1)
		img = win.assets.wall_br;
	return (img);
}

int	fill_win(t_main win)
{
	size_t	i;
	int		x;
	int		y;

	i = -1;
	x = 0;
	y = 0;
	while (++i < ft_sstrlen(win.map))
	{
		find_x_y(win, i, &x, &y);
		img_display(win, win.map[(win.map_w + 1) * y + x], x * 96, y * 96);
	}
}