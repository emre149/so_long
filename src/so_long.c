/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:18:12 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/01 16:00:19 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

bool	clean_exit(t_main *game)
{
	int	line;

	line = 0;
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	while (line < game->height - 1)
		free(game->map[line++]);
	free(game->map);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_main	so_long;

	if (argc != 2)
		return (write(1, "./so_long {MAP.ber}", 19));
	ft_memset (&so_long, 0, sizeof(t_main));
}
