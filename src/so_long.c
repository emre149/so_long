/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:45:52 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/17 14:11:56 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_main	t_main;

	if (argc == 2)
	{
		t_main.mlx_ptr = NULL;
		t_main.win_ptr = NULL;
		t_main.map = NULL;
		t_main.player = NULL;
		t_main.empty = NULL;
		t_main.collectables = NULL;
		t_main.wall = NULL;
		t_main.total_moves = 0;
		t_main.item_found = 0;
		t_main.exit_found = false;
		store_map(&t_main, argv);
		check_inputs(&t_main);
		win_init(&t_main);
		(free_all(&t_main));
	}
	ft_putendl_fd("Error\nInvalid number of arguments", 2);
	return (0);
}

void	win_init(t_main *win)
{
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
		malloc_exit(win);
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->width * 32, win->height * 32, "so_long");
	if (!win->win_ptr)
		mlx_exit(win);
	win->current_i = win->start_i;
	win->current_j = win->start_j;
	win_display(win);
	mlx_hook(win->win_ptr, KeyPress, KeyPressMask, &handle_keypress, win);
	mlx_hook(win->win_ptr, DestroyNotify, KeyPressMask, &handle_close, win);
	mlx_loop(win->mlx_ptr);
	mlx_destroy_display(win->mlx_ptr);
}

int	handle_close(t_main *win)
{
	free_all(win);
	exit(0);
	return (0);
}