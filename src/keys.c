/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:42:56 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/24 15:12:08 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int handle_keypress(int keysym, t_main *win)
{
	int	key;

	key = keysym;
	if (key == KEY_ESC)
		(free_all(win), exit(0));
	else
	{
		ft_printf("Key pressed: %d\n", key);
		if (handle_moves(win, key, win->current_i, win->current_j))
		{
			ft_printf("Move successful. New position: (%d, %d)\n", win->current_i, win->current_j);
			win->total_moves++;
			ft_printf("Total moves: %d\n", win->total_moves);
		}
	}
	return (0);
}