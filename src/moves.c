/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:52:47 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/24 14:35:41 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int handle_moves(t_main *win, int key, int i, int j)
{
    if ((key == KEY_RIGHT || key == KEY_D) && move_to(win, i, ++j) == 1)
        img_display(win, win->empty, i, j - 1); // Adjust position back for display
    else if ((key == KEY_LEFT || key == KEY_A) && move_to(win, i, --j) == 1)
        img_display(win, win->empty, i, j + 1); // Adjust position back for display
    else if ((key == KEY_DOWN || key == KEY_S) && move_to(win, ++i, j) == 1)
        img_display(win, win->empty, i - 1, j); // Adjust position back for display
    else if ((key == KEY_UP || key == KEY_W) && move_to(win, --i, j) == 1)
        img_display(win, win->empty, i + 1, j); // Adjust position back for display
    else
        return (0);

    return (1); // Indicate a move was attempted
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
