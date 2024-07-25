/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:31:39 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/25 19:38:02 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_img_opened(t_main *win)
{
	t_assets	*a;

	a = &(win->assets);
	if (!a->bg_2_1 || !a->bg_2_2 || !a->bg_1 || !a->chest_o || !a->chest || \
		!a->wall || !a->exit || !a->player || !a->wall_bl || !a->wall_br || \
		!a->wall_tl || !a->wall_tr || !a->wall_t || !a->wall_b || !a->wall_l \
		|| !a->wall_r)
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
	a->bg_2_1 = mlx_xpm_file_to_image(mlx, "./assets/bg_2_1.xpm", t, t);
	a->bg_2_2 = mlx_xpm_file_to_image(mlx, "./assets/bg_2_2.xpm", t, t);
	a->bg_1 = mlx_xpm_file_to_image(mlx, "./assets/bg.xpm", t, t);
	a->chest_o = mlx_xpm_file_to_image(mlx, "./assets/chest_o.xpm", t, t);
	a->chest = mlx_xpm_file_to_image(mlx, "./assets/chest.xpm", t, t);
	a->wall = mlx_xpm_file_to_image(mlx, "./assets/wall.xpm", t, t);
	a->exit = mlx_xpm_file_to_image(mlx, "./assets/exit.xpm", t, t);
	a->player = mlx_xpm_file_to_image(mlx, "./assets/player.xpm", t, t);
	a->wall_bl = mlx_xpm_file_to_image(mlx, "./assets/wall_bl.xpm", t, t);
	a->wall_br = mlx_xpm_file_to_image(mlx, "./assets/wall_br.xpm", t, t);
	a->wall_tl = mlx_xpm_file_to_image(mlx, "./assets/wall_tl.xpm", t, t);
	a->wall_tr = mlx_xpm_file_to_image(mlx, "./assets/wall_tr.xpm", t, t);
	a->wall_t = mlx_xpm_file_to_image(mlx, "./assets/wall_t.xpm", t, t);
	a->wall_b = mlx_xpm_file_to_image(mlx, "./assets/wall_b.xpm", t, t);
	a->wall_l = mlx_xpm_file_to_image(mlx, "./assets/wall_l.xpm", t, t);
	a->wall_r = mlx_xpm_file_to_image(mlx, "./assets/wall_r.xpm", t, t);
	check_img_opened(win);
	return (0);
}

int	close_img(t_main *g)
{
	if (g->assets.bg_2_1)
		mlx_destroy_image(g->mlx, g->assets.bg_2_1);
	if (g->assets.bg_2_2)
		mlx_destroy_image(g->mlx, g->assets.bg_2_2);
	if (g->assets.bg_1)
		mlx_destroy_image(g->mlx, g->assets.bg_1);
	if (g->assets.chest_o)
		mlx_destroy_image(g->mlx, g->assets.chest_o);
	if (g->assets.chest)
		mlx_destroy_image(g->mlx, g->assets.chest);
	if (g->assets.wall)
		mlx_destroy_image(g->mlx, g->assets.wall);
	if (g->assets.exit)
		mlx_destroy_image(g->mlx, g->assets.exit);
	if (g->assets.player)
		mlx_destroy_image(g->mlx, g->assets.player);
	return (0);
}

int	close_img_wall(t_main *g)
{
	if (g->assets.wall_bl)
		mlx_destroy_image(g->mlx, g->assets.wall_bl);
	if (g->assets.wall_br)
		mlx_destroy_image(g->mlx, g->assets.wall_br);
	if (g->assets.wall_tl)
		mlx_destroy_image(g->mlx, g->assets.wall_tl);
	if (g->assets.wall_tr)
		mlx_destroy_image(g->mlx, g->assets.wall_tr);
	if (g->assets.wall_t)
		mlx_destroy_image(g->mlx, g->assets.wall_t);
	if (g->assets.wall_b)
		mlx_destroy_image(g->mlx, g->assets.wall_b);
	if (g->assets.wall_l)
		mlx_destroy_image(g->mlx, g->assets.wall_l);
	if (g->assets.wall_r)
		mlx_destroy_image(g->mlx, g->assets.wall_r);
	return (0);
}
