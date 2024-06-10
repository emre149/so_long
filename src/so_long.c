/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:18:12 by ededemog          #+#    #+#             */
/*   Updated: 2024/06/10 16:58:12 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void		*mlx_p;
	void		*mlx_w;
	t_images	images;

	mlx_p = mlx_init();
	if (!mlx_p)
		return (1);
	mlx_w = mlx_new_window(mlx_p, 800, 600, "so_long");
	if (!mlx_w)
		return (free(mlx_p), 1);

    images.wall = mlx_xpm_file_to_image(mlx_p, "path/to/wall.xpm", &(images.wall_width), &(images.wall_height));
    images.floor = mlx_xpm_file_to_image(mlx_p, "path/to/floor.xpm", &(images.floor_width), &(images.floor_height));
    images.collectible = mlx_xpm_file_to_image(mlx_p, "path/to/collectible.xpm", &(images.collectible_width), &(images.collectible_height));
    images.exit = mlx_xpm_file_to_image(mlx_p, "path/to/exit.xpm", &(images.exit_width), &(images.exit_height));
	images.position = mlx_xpm_file_to_image(mlx_p, "path/to/position.xpm", &(images.exit_width), &(images.exit_height));
	
	read_and_
	
	mlx_loop(mlx_p);
	free(mlx_p);
	return (0);
}