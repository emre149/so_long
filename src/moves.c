/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:52:47 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/15 20:00:45 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_moves(t_main *win, int key, int i, int j)
{
	if (key == 119)
	{
		if (move_there(win, i - 1, j))
			return (1);
	}
	else if (key == 115)
	{
		if (move_there(win, i + 1, j))
			return (1);
	}
	else if (key == 97)
	{
		if (move_there(win, i, j - 1))
			return (1);
	}
	else if (key == 100)
	{
		if (move_there(win, i, j + 1))
			return (1);
	}
	return (0);
}