/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:27:02 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/17 18:01:03 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	store_map(t_main *win, char **argv)
{
	char	*str;
	char	*lines;
	char	*buff;
	int		fd;

	(check_argv(win, argv), fd = open(argv[1], O_RDONLY));
	str = get_next_line(fd);
	buff = NULL;
	lines = NULL;
	while (str)
	{
		buff = lines;
		lines = ft_strjoin(buff, str);
		if (!lines)
			(free(str), malloc_exit(win));
		if (buff)
			free(buff);
		(free(str), str = get_next_line(fd));
	}
	win->map = ft_split(lines, '\n');
	free(lines);
	if (!win->map || !win->map[0])
		malloc_exit(win);
	win->col_len = ft_tab_len(win->map);
	win->line_len = ft_strlen((win->map)[0]);
}


void	check_argv(t_main *win, char **argv)
{
	int		fd;
	int		i;
	char	buff[1];

	i = 0;
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e' || argv[1][i - 3] != 'b' || argv[1][i - 4] != '.')
		free_all_and_errors(win, "Error\nWrong file extension, please user .ber\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		free_all_and_errors(win, "Error\nFile not found\n");
	if (read(fd, buff, 0) == -1)
		free_all_and_errors(win, "Error\nFile not readable\n");
	close(fd);
}

void	check_inputs(t_main *win)
{
	char 	**map_cpy;
	int		i;

	i = 0;
	(exit_check(win), collectable_check(win), start_check(win));
	(closed_check(win), rectangle_check(win), win->item_found = 0);
	map_cpy = malloc(sizeof(char *) * (win->col_len + 1));
	if (!map_cpy)
		malloc_exit(win);
	map_cpy[win->col_len] = NULL;
	while (win->map[i])
	{
		map_cpy[i] = ft_strdup(win->map[i]);
		if (!map_cpy[i])
			(ft_fdt(&map_cpy), malloc_exit(win));
		i++;
	}
	is_map_valid(win, map_cpy, win->start_i, win->start_j);
	ft_fdt(&map_cpy);
	if (win->item_found != win->item_nbr)
		free_all_and_errors(win, "Error\nMissing collectable\n");
	if (win->exit_found == false)
		free_all_and_errors(win, "Error\nMissing exit\n");
}

int	ft_tab_len(char **tab)
{
	int	i;

	if (!tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}
