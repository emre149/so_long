/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:23:03 by ededemog          #+#    #+#             */
/*   Updated: 2023/11/20 19:26:14 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *pointer, size_t count)
{
	size_t	i;
	int		value;

	i = 0;
	value = 0;
	while (i < count)
	{
		*(unsigned char *)(pointer + i) = (unsigned char)value;
		i++;
	}
}
/*
#include <stdio.h>

int	main()
{
	char mem[50];
	ft_bzero(mem, 50);
	for (int i = 0; i < 50; i++)
		printf("%c", mem[i]);
	printf("\n");
	return 0;
}
*/