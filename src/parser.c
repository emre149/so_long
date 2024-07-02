/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:05:40 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/02 17:16:30 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	line_parsing(char *line, int y, void *mlx_p, void *mlx_w, t_main *images)
{
    int	i;
    int	x;

    i = 0;
    x = 0;
    while (line[i]!= '\n') {
        c_interpretor(line[i], x, y, mlx_p, mlx_w, images); // Ensure c_interpretor is declared
        x += HEIGHT; // Adjust this value as needed
        i++;
    }
    ft_printf("\n");
}

void	add_line_to_map(char ***map, const char *line, size_t *height)
{
    (*height)++;
    *map = realloc(*map, sizeof(**map) * (*height + 1));
    (*map)[*height - 1] = ft_strdup(line);
    (*map)[*height] = NULL;
}

static int width_map(char *str)
{
    int width;

    width = 0;
    while (!str[width])
        width++;
    return width;
}

void read_and_process_map(const char *filename, t_main *game)
{
    char *line;
    int fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("Erreur d'ouverture du fichier");
        return;
    }

    game->map = NULL; // Initialize map pointer
    game->lines = 0; // Initialize lines count

    while ((line = get_next_line(fd))!= NULL) {
        add_line_to_map(&game->map, line, (size_t *)&game->lines); // Cast to size_t*
        free(line);
    }
    close(fd);
}

void free_map(char **map, int lines)
{
    int i;
    
    i = 0;
    while (i < lines) {
        free(map[i]);
        i++;
    }
    free(map);
}

int main(int argc, char **argv)
{
    t_main game;

    if (argc!= 2) {
        fprintf(stderr, "Usage %s <map_file>\n", argv[0]);
        return 1;
    }

    read_and_process_map(argv[1], &game);

    free_map(game.map, game.lines);

    return 0;
}
