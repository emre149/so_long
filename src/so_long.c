/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:18:12 by ededemog          #+#    #+#             */
/*   Updated: 2024/04/25 17:45:38 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(void)
{
	void	*mlx_p;
	void	*mlx_w;

	mlx_p = mlx_init();
	if (!mlx_p)
		return (1);
	mlx_w = mlx_new_window(mlx_p, 600, 400, "hi :0");
	if (!mlx_w)
		return (free(mlx_p), 1);
	mlx_loop(mlx_p);
	free(mlx_p);
	return (0);
}