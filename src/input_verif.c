/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:27:02 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/16 12:28:56 by ededemog         ###   ########.fr       */
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