/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:18:12 by ededemog          #+#    #+#             */
/*   Updated: 2024/05/01 18:55:47 by ededemog         ###   ########.fr       */
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
	void	*mlx_p;
	void	*mlx_w;
	void	*mlx_i;
	// char	*buffer;
	t_data	img;

	mlx_p = mlx_init();
	if (!mlx_p)
		return (1);
	mlx_i = mlx_new_image(mlx_p, 800, 600);
	mlx_w = mlx_new_window(mlx_p, 800, 600, "so_long");
	if (!mlx_w)
		return (free(mlx_p), 1);
	img.img = mlx_new_image(mlx_p, 500, 300);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx_p, mlx_w, img.img, 0, 0);
	mlx_loop(mlx_p);
	free(mlx_p);
	return (0);
}