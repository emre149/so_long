/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:50:19 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/17 14:55:39 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_all(t_main *win)
{
	if (!win)
		return;
	
	ft_fdt(&win->map);
	mlx_destroy_imgs(win);
	if (win->mlx_ptr && win->win_ptr)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (win->mlx_ptr)
	{
		mlx_destroy_display(win->mlx_ptr);
		free(win->mlx_ptr);
	}
}

void	free_errors(t_main *win, char *err_msg)
{
	handle_error(win, err_msg, 1);
}

void	free_all_and_errors(t_main *win, char *err_msg)
{
	free_all(win);
	ft_putendl_fd(err_msg, 2);
	exit(1);
}

void	malloc_exit(t_main *win)
{
	handle_error(win, "Error\nMalloc failed\n", 1);
}

void	mlx_exit(t_main *win)
{
	if (win)
		free_all(win);
	ft_putendl_fd("Error\nmlx failed\n", 2);
	exit(1);
}

void	handle_error(t_main *win, char *err_msg, int err_code)
{
	free_all(win);
	ft_putendl_fd(err_msg, STDERR_FILENO);
	exit(err_code);
}

void	mlx_destroy_imgs(t_main *win)
{
	if (win->mlx_ptr)
	{
		if (win->player)
			(mlx_destroy_image(win->mlx_ptr, win->player),
				win->player = NULL);
		if (win->exit)
			(mlx_destroy_image(win->mlx_ptr, win->exit),
				win->exit = NULL);
		if (win->collectables)
			(mlx_destroy_image(win->mlx_ptr, win->collectables),
				win->collectables = NULL);
		if (win->wall)
			(mlx_destroy_image(win->mlx_ptr, win->wall),
				win->wall = NULL);
		if (win->empty)
			(mlx_destroy_image(win->mlx_ptr, win->empty),
				win->empty = NULL);
	}
}

