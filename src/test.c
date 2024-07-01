#include "../inc/so_long.h"

int main(void)
{
    t_main so_long;

    // Initialize all members of so_long to safe defaults
    so_long.mlx_ptr = NULL; // Pointer to MLX instance
    so_long.win_ptr = NULL; // Pointer to the window
    so_long.wall = NULL; // Pointer to the wall texture image
    so_long.player = NULL; // Pointer to the player sprite
    so_long.empty = NULL; // Pointer to the empty space sprite
    so_long.collectables = NULL; // Pointer to collectable item sprites
    so_long.exit = NULL; // Pointer to the exit sprite
    so_long.map = NULL; // Pointer to the game map
    so_long.height = 0; // Height of the game window
    so_long.width = 0; // Width of the game window
    so_long.lines = 0; // Number of lines in the map
    so_long.cols = 0; // Number of columns in the map
    so_long.start_i = 0; // Starting row index
    so_long.start_j = 0; // Starting column index
    so_long.actual_i = 0; // Current row index
    so_long.actual_j = 0; // Current column index
    so_long.items_nbr = 0; // Total number of items
    so_long.items_collected = 0; // Number of collected items
    so_long.total_moves = 0; // Total moves made by the player
    so_long.exit_found = false; // Flag indicating if the exit has been reached

    // Initialize MLX and create a window
    so_long.mlx_ptr = mlx_init();
    if (!so_long.mlx_ptr) {
        fprintf(stderr, "Failed to initialize MLX.\n");
        return 1;
    }

    so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, WIDTH * 32, HEIGHT * 32, "So Long");
    if (!so_long.win_ptr) {
        fprintf(stderr, "Failed to create a new window.\n");
        return 1;
    }

    // Load the wall texture
    so_long.wall = mlx_xpm_file_to_image(so_long.mlx_ptr, WALL_x, &so_long.width, &so_long.height);
    if (!so_long.wall) {
        fprintf(stderr, "Failed to load wall texture.\n");
        return 1;
    }

    // Draw the wall texture onto the window
    mlx_put_image_to_window(so_long.mlx_ptr, so_long.win_ptr, so_long.wall, 0, 0);

    // Main event loop
    mlx_loop(so_long.mlx_ptr);

    return 0;
}
