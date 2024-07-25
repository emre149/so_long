/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:12:19 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/24 16:28:20 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	clean_exit(t_main *win)
{
	if (win->game_state == 1 || win->game_state == 2)
		free(win->map);
	if (win->game_state == 3)
	{
		free(win->map);
		close_img(win);
		close_img_wall(win);
		if (win->mlx_win)
			mlx_destroy_window(win->mlx, win->mlx_win);
		free(win->mlx);
	}
	if (win->game_state == 4)
	{
		free(win->map);
		close_img(win);
		close_img_wall(win);
		mlx_destroy_window(win->mlx, win->mlx_win);
		if (win->mlx)
			mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	exit (0);
	return (0);
}

int	key_handler(int keycode, t_main *win)
{
	if (keycode == KEY_ESC)
		close_program(win);
	if (keycode == KEY_W || keycode == KEY_UP || keycode == 32)
		move_check(win, 't');
	if (keycode == KEY_S || keycode == KEY_DOWN || keycode == 65505)
		move_check(win, 'b');
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_check(win, 'l');
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_check(win, 'r');
	return (0);
}

void	event_listener(t_main *win)
{
	mlx_hook(win->mlx_win, 17, 1L << 17, clean_exit, win);
	mlx_hook(win->mlx_win, 2, 1L << 0, key_handler, win);
}

int	main(int argc, char **argv)
{
	t_main	win;

	ft_memset(&win, 0, sizeof(t_main));
	win.game_state = 0;
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (clean_exit(&win), 1);	
	}
	check_map(&win, argv[1]);
	win.collect = item_occ(win.map, COLLECTABLE);
	win.game_state = 3;
	win.mlx = mlx_init();
	if (!win.mlx)
		return (clean_exit(&win), 1);
	win.player_pos = index(win.map, PLAYER);
	open_img(win.mlx, &win);
	win.game_state = 4;
	win.mlx_win = mlx_new_window(win.mlx, win.map_w * WIDTH, win.map_h * WIDTH, "so_long");
	if (!win.mlx_win)
		return (clean_exit(&win), 1);
	fill_win(win);
	event_listener(&win);
	mlx_loop(win.mlx);
}