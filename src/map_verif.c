/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:08:03 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/25 18:51:18 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_closed(char *map)
{
	int	i;
	int	j;
	int	line_l;

	i = -1;
	line_l = line_len(map);
	while (++i <= item_occ(map, '\n'))
	{
		j = i * (line_l + 1);
		if (i == 0 || i == item_occ(map, '\n'))
		{
			while (j < i * (line_l + 1) + line_l)
				if (map[j++] != WALL)
					return (1);
		}
		else
		{
			if (map[j] != WALL || map[j + line_l - 1] != WALL)
				return (1);
		}
	}
	return (0);
}

int	is_same_len(char *map)
{	
	int	i;
	int	j;
	int	line_l;

	line_l = line_len(map);
	j = 0;
	while (j <= item_occ(map, '\n'))
	{
		i = 0;
		while (map[i + j * (line_l + 1)] && map[i + j * (line_l + 1)] != '\n')
			i++;
		if (i != line_l)
			return (1);
		j++;
	}
	return (0);
}

int	check_items(char *map)
{
	int	i;

	i = -1;
	while (map[++i])
		if (map[i] != WALL && map[i] != EMPTY && map[i] != COLLECTABLE && map[i] != PLAYER \
			&& map[i] != EXIT && map[i] != '\n')
			return (1);
	return (0);
}


int	check_filename(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	i--;
	if (i < 4)
		return (1);
	if (filename[i] != 'r' || filename[i - 1] != 'e' || filename[i - 2] != 'b' \
		|| filename[i - 3] != '.')
		return (1);
	if (filename[i - 4] == '/')
		return (1);
	return (0);
}

int	check_map(t_main *win, char *filename)
{
	if (check_filename(filename))
		return (ft_printf("Invalid filename.\n"), clean_exit(win), 1);
	win->map = ft_calloc(map_size(win, filename) + 1, sizeof(char));
	if (!win->map)
		return (ft_printf("Malloc error.\n"), clean_exit(win), 0);
	win->game_state = 1;
	get_map(win, filename);
	win->map_h = item_occ(win->map, '\n') + 1;
	win->map_w = line_len(win->map);
	if (check_items(win->map))
		return (ft_printf("No map.\n"), clean_exit(win));
	if (item_occ(win->map, PLAYER) != 1)
	{
		ft_printf("%d\n", item_occ(win->map, PLAYER));
		return (ft_printf("No start.\n")), clean_exit(win);
	}
	if (item_occ(win->map, EXIT) != 1)
		return (ft_printf("No exit.\n")), clean_exit(win);
	if (item_occ(win->map, COLLECTABLE) < 1)
		return (ft_printf("No collectables.\n")), clean_exit(win);
	if (is_closed(win->map))
		return (ft_printf("Map is not closed.\n"), clean_exit(win));
	if (is_same_len(win->map))
		return (ft_printf("Invalid integrity.\n"), clean_exit(win));
	win->game_state = 2;
	if (check_map_can_be_solved(win->map, win))
		return (ft_printf("Map is unsolvable.\n"), clean_exit(win));
	return (0);
}