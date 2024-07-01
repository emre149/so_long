/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:18:12 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/01 15:01:30 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	load_textures(t_main *main, int tile_type, char *path)
{

	printf("%s\n", path);
	printf("%d\n", tile_type);
	printf("%d\n", main->w_width);
	printf("%d\n", main->w_height);

	int	w;
	int	h;

	w = 32;
	h = 32;
	
	if (tile_type < 0 || tile_type >= 5)
		return;
	// main->textures[tile_type] = mlx_xpm_file_to_image(main->mlx_ptr, path, &main->i_width, &main->i_height);
	main->textures[tile_type] = mlx_xpm_file_to_image(main->mlx_ptr, path, &w, &h);
	if (!main->textures[tile_type])
	{
		printf("Failed to load texture: %s\n", path);
		return;
	}
}

int	main()
{
	t_main 	main;
	int		i;

	i = 0;
	main.mlx_ptr = NULL;
	main.win_ptr = NULL;
	main.map = NULL;
	main.img = NULL;
	while (i < 5)
	{
		main.textures[i] = NULL;
		i++;
	}
	
	main.i_height = 0;
	main.i_width = 0;
	main.w_width = 800;
	main.w_height = 600;

	char *wall_texture_path = "assets/1.xpm";

	if (!wall_texture_path)
		return (printf("Texture not loaded.\n"));
	else
		load_textures(&main, WALL, wall_texture_path);

	main.win_ptr = mlx_new_window(main.mlx_ptr, main.w_width, main.w_height, "cacabudin");

	int	x;
	int	y;

	x = 20;
	y = 20;

	if (main.textures[WALL])
		mlx_put_image_to_window(main.mlx_ptr, main.win_ptr, main.textures[WALL], x, y);

	mlx_loop(main.mlx_ptr);
	printf("hi");
	return (0);
}