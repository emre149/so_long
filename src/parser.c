/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:35:43 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/17 18:02:35 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"	

void is_map_valid(t_main *win, char **map_cpy, int i, int j)
{
	if (map_cpy[i][j] == '1')
		return;
	if (map_cpy[i][j] == 'E')
	{
		win->exit_found = true;
		return;
	}
	if (map_cpy[i][j] == 'C')
		win->item_found++;
	map_cpy[i][j] = '1';
	if (win->map[i][j + 1] != '1')
		is_map_valid(win, map_cpy, i, j + 1);
	if (win->map[i][j - 1] != '1')
		is_map_valid(win, map_cpy, i, j - 1);
	if (win->map[i + 1][j] != '1')
		is_map_valid(win, map_cpy, i + 1, j);
	if (win->map[i - 1][j] != '1')
		is_map_valid(win, map_cpy, i - 1, j);
}