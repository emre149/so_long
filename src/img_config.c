/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:31:39 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/25 19:15:23 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


int	check_img_opened(t_main *win)
{
	t_assets	*a;

	a = &(win->assets);
	if (!a->bg_1 || !a->exit || !a->chest || !a->chest_o || !a->player)
		return (clean_exit(win));
	return (0);
}

int	open_imgs(void *mlx, t_main *win)
{
	t_assets	*a;
	int			*t;
	int			p;

	t = &p;
	a = &(win->assets);
	a->bg_1 = mlx_xpm_file_to_image(mlx, "./assets/background.xpm", t, t);
	a->exit = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm", t, t);
	a->chest = mlx_xpm_file_to_image(mlx, "./assets/chest_closed.xpm", t, t);
	a->chest_o = mlx_xpm_file_to_image(mlx, "./assets/chest_open.xpm", t, t);
	a->player = mlx_xpm_file_to_image(mlx, "./assets/player.xpm", t, t);
	check_img_opened(win);
	return (0);
}

int	close_img(t_main *g)
{
	if (g->assets.bg_1)
		mlx_destroy_image(g->mlx, g->assets.bg_1);
	if (g->assets.exit)
		mlx_destroy_image(g->mlx, g->assets.exit);
	if (g->assets.chest)
		mlx_destroy_image(g->mlx, g->assets.chest);
	if (g->assets.chest_o)
		mlx_destroy_image(g->mlx, g->assets.chest_o);
	if (g->assets.player)
		mlx_destroy_image(g->mlx, g->assets.player);
	return (0);
}