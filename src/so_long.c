/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:18:12 by ededemog          #+#    #+#             */
/*   Updated: 2024/06/28 17:00:40 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_textures(t_data *data, int tile_type, char *path)
{

	printf("%s\n", path);
	printf("%d\n", tile_type);
	printf("%d\n", data->w_width);
	printf("%d\n", data->w_height);

	int	w;
	int	h;

	w = 32;
	h = 32;
	
	if (tile_type < 0 || tile_type >= 5)
		return;
	// data->textures[tile_type] = mlx_xpm_file_to_image(data->mlx_ptr, path, &data->i_width, &data->i_height);
	data->textures[tile_type] = mlx_xpm_file_to_image(data->mlx_ptr, path, &w, &h);
	if (!data->textures[tile_type])
	{
		printf("Failed to load texture: %s\n", path);
		return;
	}
}

int	main()
{
	t_data data;

	data.mlx_ptr = mlx_init();

	data.w_width = 800;
	data.w_height = 600;

	char *wall_texture_path = "assets/1.xpm";

	if (!wall_texture_path)
		return (printf("Texture not loaded.\n"));
	else
		load_textures(&data, WALL, wall_texture_path);

	data.win_ptr = mlx_new_window(data.mlx_ptr, data.w_width, data.w_height, "cacabudin");

	int	x;
	int	y;

	x = 20;
	y = 20;

	if (data.textures[WALL])
		mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[WALL], x, y);

	mlx_loop(data.mlx_ptr);
	printf("hi");
	return (0);
}