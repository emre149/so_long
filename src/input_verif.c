/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:27:02 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/16 18:31:45 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void store_map(t_main *so_long, char **argv)
{
    char *str;
    char *lines;
    char *buff;
    int fd;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        malloc_exit(so_long); // Assuming you want to exit if file can't be opened.
    str = ft_get_next_line(fd);
    buff = NULL;
    lines = NULL;
    while (str)
    {
        buff = lines;
        lines = ft_strjoin(buff, str);
        if (!lines)
        {
            free(str);
            malloc_exit(so_long);
        }
        if (buff)
            free(buff);
        free(str);
        str = ft_get_next_line(fd);
    }
    so_long->map = ft_split(lines, '\n');
    free(lines);
    if (!so_long->map || !so_long->map[0])
        malloc_exit(so_long);
    so_long->col_len = ft_tab_len(so_long->map); // Assuming you have a function to calculate the number of lines.
    so_long->line_len = ft_strlen(so_long->map[0]); // Assuming the map is rectangular.
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
	(check_map_exit(win), check_map_item(win), check_map_start(win));
	(check_map_closed(win), check_map_rectangle(win), win->item_nbr = 0);
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
	check_map_valid(win, map_cpy, win->start_i, win->start_j);
	if (win->item_nbr != win->item_found)
		(ft_fdt(&map_cpy), free_all_and_errors(win, "Error\nMissing collectables\n"));
	if (win->exit_found == false)
		(ft_fdt(&map_cpy), free_all_and_errors(win, "Error\nMissing exit\n"));
}