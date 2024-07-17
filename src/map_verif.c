/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:06:02 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/17 17:34:50 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	exit_check(t_main *win)
{
	int	i;
	int j;
	int	exit_point;

	i = 0;
	j = 0;
	exit_point = 0;
	while (win->map[i][j])
	{
		j = 0;
		while (win->map[i][j])
		{
			if (win->map[i][j] == 'E')
				exit_point++;
			if (win->map[i][j] != 'E' && win->map[i][j] != '0'
				&& win->map[i][j] != '1' && win->map[i][j] != 'C'
				&& win->map[i][j] != 'P')
				free_all_and_errors(win, "Error\nMap is invalid\n");
			j++;
		}
		i++;
	}
}

void	collectable_check(t_main *win)
{
	int	i;
	int	j;
	int	collectable_point;

	i = 0;
	collectable_point = 0;
	win->item_nbr = 0;
	while (win->map[i])
	{
		j = 0;
		while (win->map[i][j])
		{
			if (win->map[i][j] == 'C')
			{
				collectable_point++;
				win->item_nbr++;
			}
			j++;
		}
		i++;
	}
	if (collectable_point < 1)
		free_all_and_errors(win, "Error\nNo collectable found\n");
}

void	start_check(t_main *win)
{
	int	i;
	int	j;
	int	start_point;

	i = 0;
	start_point = 0;
	while (win->map[i])
	{
		j = 0;
		while (win->map[i][j])
		{
			if (win->map[i][j] == 'P')
			{
				start_point++;
				win->start_i = i;
				win->start_j = j;
			}
			j++;
		}
		i++;
	}
	if (start_point != 1)
		free_all_and_errors(win, "Error\nNo or multiple starting points\n");
}

void	rectangle_check(t_main *win)
{
	int	i;
	int	li_len;

	i = 0; 
	li_len = win->line_len;
	while (win->map[i])
	{
		if (ft_strlen(win->map[i]) != li_len)
			free_all_and_errors(win, "Error\nMap is not a rectangle\n");
		i++;
	}
}

void	closed_check(t_main *win)
{
	int	i;
	int	j;

	i = 0;
	while (win->map[i])
	{
		j = 0;
		while (win->map[i][j])
		{
			if (i == 0 || i == win->col_len - 1 || j == 0
				|| j == win->line_len - 1)
			{
				if (win->map[i][j] != '1')
					free_all_and_errors(win, "Error\nMap is not closed\n");
			}
			j++;
		}
		i++;
	}
}