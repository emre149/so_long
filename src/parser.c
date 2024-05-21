/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:05:40 by ededemog          #+#    #+#             */
/*   Updated: 2024/05/21 16:45:31 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	c_interpretor(char c, int x, int y, void *mlx_p, t_images *images)
{
	void	*image_to_draw;
	
	if (c == '1')
	{
		ft_printf("1");
	}
	else if (c == '0')
	{
		ft_printf("0");
	}
	else if (c == 'P')
	{
		ft_printf("P");
	}
	else if (c == 'C')
	{
		ft_printf("C");
	}
	else if (c == 'E')
	{
		ft_printf("E");
	}
	return (0);
	mlx_put_image_to_window()
}

void	line_parsing(char *line, int y, void *mlx_p, t_images *images)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (line[i] != '\0')
	{
		c_interpretor(line[i], x, y, mlx_p, images);
		x += IMAGE_WIDTH; // to change ofc
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
