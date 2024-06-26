#include "../inc/so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	printf("Window closed\n");
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d \n", keysym);
	return (0);
}

int		main(void)
{
	t_data	data;
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("Current working directory: %s\n", cwd);
	} else {
		perror("getcwd() error");
	}

	char *file_path = "../assets/pfp.xpm";
	if (access(file_path, F_OK) != -1) {
		printf("File exists: %s\n", file_path);
	} else {
		perror("access() error");
		return 1;
	}

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
	{
		printf("Failed to initialize mlx\n");
		return (1);
	}

	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "solong");
	if (!data.win_ptr)
	{
		printf("Failed to create window\n");
		free(data.mlx_ptr);
		return (1);
	}

	void *image = mlx_xpm_file_to_image(data.mlx_ptr, file_path, &data.i_width, &data.i_height);
	if (!image)
	{
		printf("Failed to load image '%s': %s\n", file_path, strerror(errno));
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	else
	{
		printf("Image '%s' loaded successfully\n", file_path);
	}

	int x = 100;
	int y = 50;
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, image, x, y);

	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	mlx_loop(data.mlx_ptr);

	// Free image before exiting
	mlx_destroy_image(data.mlx_ptr, image);

	return (0);
}
