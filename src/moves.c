/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:52:47 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/17 15:01:25 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_moves(t_main *win, int key, int i, int j)
{
	if (key == KEY_RIGHT || key == KEY_D)
	{
		if (move_to(win, i - 1, j))
			return (1);
	}
	else if (key == 115)
	{
		if (move_to(win, i + 1, j))
			return (1);
	}
	else if (key == 97)
	{
		if (move_to(win, i, j - 1))
			return (1);
	}
	else if (key == 100)
	{
		if (move_to(win, i, j + 1))
			return (1);
	}
	return (0);
}

int	move_to(t_main *win, int i, int j)
{
	if (win->map[i][j] == '1')
		return (0);
	if (win->map[i][j] == 'E' && win->item_found != win->item_nbr)
		return (0);
	else if (win->map[i][j] == 'C')
	{
		win->item_found++;
		win->map[i][j] = '0';
	}
	else if (win->map[i][j] == 'E' && win->item_found == win->item_nbr)
		(free_all(win), exit(0));
	img_display(win, win->player, i, j);
	win->current_i = i;
	win->current_j = j;
	return (1);
}
