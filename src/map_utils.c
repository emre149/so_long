/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:45:13 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/25 15:47:07 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_size(t_main *win, char *filename)
{
	int		fd;
	int		i;
	int		rt_value;
	char	c;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_);
}