/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:05:40 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/26 14:16:04 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

t_map	*parsing(const char *file)
{
	int	fd;

	fd = open("../maps/classic.ber", O_RDONLY);
	if (fd < 0)
	{
		perror("Error trying opening the map.\n");
		exit(1);
	}

	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit(1);
	read(fd, &map->width, sizeof(int));
	read(fd, &map->height, sizeof(int));
}