/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:50:19 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/16 17:04:52 by ededemog         ###   ########.fr       */
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

void	mlx_destroy_imgs(t_main *so_long)
{
	if (so_long->mlx_ptr)
	{
		if (so_long->player)
			(mlx_destroy_image(so_long->mlx_ptr, so_long->player),
				so_long->player = NULL);
		if (so_long->exit)
			(mlx_destroy_image(so_long->mlx_ptr, so_long->exit),
				so_long->exit = NULL);
		if (so_long->collectables)
			(mlx_destroy_image(so_long->mlx_ptr, so_long->collectables),
				so_long->collectables = NULL);
		if (so_long->wall)
			(mlx_destroy_image(so_long->mlx_ptr, so_long->wall),
				so_long->wall = NULL);
		if (so_long->empty)
			(mlx_destroy_image(so_long->mlx_ptr, so_long->empty),
				so_long->empty = NULL);
	}
}

