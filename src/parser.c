/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:05:40 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/01 16:33:09 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	line_parsing(char *line, int y, void *mlx_p,void *mlx_w, t_main *images)
{
	t_main	main;
	
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (line[i] != '\0')
	{
		c_interpretor(line[i], x, y, mlx_p, mlx_w, images);
		x += HEIGHT; // to change ofc
		i++;
	}
	ft_printf("\n");
}

void read_and_process_map(const char *filename, t_main *game)
{
    char *line;
    int fd = open(filename, O_RDONLY);
	int	x;
	int	y;

	x = 0;
	y = 0;
    if (fd == -1)
	{
        perror("Erreur d'ouverture du fichier");
        return;
    }

    while ((line = get_next_line(fd)) != NULL)
	{
		while (line[x])
		{
			game->map[y][x] = line[x];
			if (line[x] == PLAYER)
			{
				game->start_i = y;
				game->start_j = x;
			}
			else if (line[x] == COLLECTABLE)
			{
				game->items_nbr++;
			}
			x++;
		}
		game->cols = x;
		free(line);
		y++;
    }
	game->lines = y;
	close(fd);
}

void	is_map_valid(t_main *game)
{
	if (!game->map || !game->map[0])
		return (0);

	int
}