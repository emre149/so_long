/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:59:30 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/29 16:06:26 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	item_occ(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	line_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	get_ind(int pos, char *map, char directions)
{
	int	i;

	i = line_len(map) + 1;
	if (map[pos] == '\n')
		return (-1);
	if (directions == 't')
		if (pos > i)
			return (pos - i);
	if (directions == 'b')
		if (pos < i * item_occ(map, '\n'))
			return (pos + i);
	if (directions == 'l')
		if (map[pos - 1] && map[pos - 1] != '\n')
			return (pos - 1);
	if (directions == 'r')
		if (map[pos + 1] && map[pos + 1] != '\n')
			return (pos + 1);
	return (-1);
}

int	find_index(char *map, char tf)
{
	int	i;

	i = 0;
	while (map[i] && map[i] != tf)
		i++;
	if (map[i] == tf)
		return (i);
	i++;
	return (-1);
}

int	find_x_y(t_main win, int pos, int *x, int *y)
{
	int	i;

	i = 0;
	*x = 0;
	*y = 0;
	while (win.map[i] && i < pos)
	{
		if (win.map[i] == '\n')
		{
			*y += 1;
			*x = 0;
		}
		else
			*x += 1;
		i++;
	}
	return (0);
}
