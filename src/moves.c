/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:26:43 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/29 16:11:15 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	move_check(t_main *win, char direction)
{
	int	temp;
	int	x;
	int	y;

	find_x_y(*win, win->player_pos, &x, &y);
	temp = get_ind(win->player_pos, win->map, direction);
	if (temp == -1)
		return (-1);
	if (win->map[temp] == WALL)
		return (0);
	if (win->map[temp] == COLLECTABLE)
	{
		win->collect--;
		move_player(*win, win->player_pos, direction);
	}
	if (win->map[temp] == EMPTY || win->map[temp] == PLAYER)
		move_player(*win, win->player_pos, direction);
	if (win->map[temp] == EXIT)
		move_player(*win, win->player_pos, direction);
	if (win->map[temp] == EXIT && win->collect == 0)
		return (clean_exit(win), 0);
	if (win->map[temp] == 'O')
		move_player(*win, win->player_pos, direction);
	win->player_pos = temp;
	return (win->move++, 0);
}

int	move_player(t_main win, int initial_pos, char direction)
{
	int	x;
	int	y;

	find_x_y(win, initial_pos, &x, &y);
	x = x * 64;
	y = y * 64;
	img_display(win, EMPTY, x, y);
	if (win.map[initial_pos] == COLLECTABLE || win.map[initial_pos] == 'O')
	{
		img_display(win, 'O', x, y);
		win.map[initial_pos] = 'O';
	}
	if (win.map[initial_pos] == EXIT)
		img_display(win, EXIT, x, y);
	if (direction == 't')
		y -= 64;
	if (direction == 'b')
		y += 64;
	if (direction == 'l')
		x -= 64;
	if (direction == 'r')
		x += 64;
	ft_printf("Total moves: %d\n", ++win.move);
	return (img_display(win, PLAYER, x, y), 0);
}
