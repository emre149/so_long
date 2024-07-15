/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:42:56 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/15 20:02:06 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int handle_keypress(int keysym, t_main *win)
{
	int	key;

	key = keysym;
	if (key == Ex)
	{
		free_all(win);
		exit(0);
	}
	else
	{
		if (handle_moves(win, key, win->current_i, win->current_j))
		{
			win->total_moves++;
			ft_printf("Total moves: %d\n", win->total_moves);
		}
	}
	return (0);
}