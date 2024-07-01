#include "../inc/so_long.h"

int main(void)
{
    t_data data;

	data.mlx_ptr = NULL;
	data.win_ptr = NULL;
	data.wall = NULL;
    // Initialize the MiniLibX library
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
    {
        // Handle error
        return (1);
    }

    // Load the XPM image (assuming it's in the assets directory relative to your program)
    // Note: It's important to initialize i_width and i_height before calling this function
    data.img = mlx_xpm_file_to_image(data.mlx_ptr, "assets/1.xpm", &data.i_width, &data.i_height);

    // Check if the image was loaded successfully
    if (!data.img)
    {
        printf("Failed to load image\n");
        return (1);
    }

    printf("Loaded image with dimensions: %d x %d\n", data.i_width, data.i_height);

    // Create a new window
    data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "Display XPM Image");
    if (!data.win_ptr)
    {
        // Handle error
        return (1);
    }

    // Display the image in the window
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);

    // Main loop to keep the window open
    mlx_loop(data.mlx_ptr);

    return (0);
}
