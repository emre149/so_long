/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:05:40 by ededemog          #+#    #+#             */
/*   Updated: 2024/06/10 17:40:42 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	c_interpretor(char c, int x, int y, void *mlx_p, void *mlx_w, t_images *images)
{
	void	*image_to_draw;
	
	if (c == '1')
	{
		image_to_draw = images->wall;
	}
	else if (c == '0')
	{
		image_to_draw = images->floor;
	}
	else if (c == 'P')
	{
		image_to_draw = images->position;
	}
	else if (c == 'C')
	{
		image_to_draw = images->collectible;
	}
	else if (c == 'E')
	{
		image_to_draw = images->exit;
	}
	return (0);
    mlx_put_image_to_window(mlx_p, mlx_w, image_to_draw, x, y);
}

void	line_parsing(char *line, int y, void *mlx_p,void *mlx_w, t_images *images)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (line[i] != '\0')
	{
		c_interpretor(line[i], x, y, mlx_p, mlx_w, images);
		x += images.width; // to change ofc
		i++;
	}
	ft_printf("\n");
}

void	read_and_process(const char *filename, void	*mlx_p, t_images *images)
{
    char *line;
    int fd = open(filename, O_RDONLY);
	int	y;

	y = 0;
    if (fd == -1)
	{
        perror("Erreur d'ouverture du fichier");
        return;
    }

    while ((line = get_next_line(fd)) != NULL)
	{
        line_parsing(line, y, mlx_p, images);
        free(line);
		y += IMAGE_HEIGHT; 
    }

    close(fd);
}
