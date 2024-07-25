/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:45:13 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/25 18:46:03 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_size(t_main *win, char *filename)
{
	int		fd;
	int		i;
	int		rt_value;
	char	c;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_printf("No map."), clean_exit(win), 0);
	rt_value = 1;
	while (rt_value)
	{
		rt_value = read(fd, &c, 1);
		if (rt_value == -1)
			return (clean_exit(win), 0);
		if (rt_value == 1)
			i++;
	}
	close(fd);
	return(i);
}

int	get_map(t_main *win, char *filename)
{
	int	rt_value;
	int	fd;
	int	i;
	char c;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_printf("No map."), clean_exit(win), 0);
	i = 0;
	rt_value = 1;
	while (rt_value > 0)
	{
		rt_value = read(fd, &c, 1);
		if (rt_value == -1)
			return (clean_exit(win), 0);
		if (rt_value != 0)
			win->map[i] = c;
		i++;
	}
	close(fd);
	return (0);
}