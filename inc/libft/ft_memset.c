/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:42:50 by ededemog          #+#    #+#             */
/*   Updated: 2023/11/21 01:29:24 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		*(unsigned char *)(pointer + i) = (unsigned char)value;
		i++;
	}
	return (pointer);
}
/*
#include <stdio.h>

int	main()
{
	char mem[50];
	ft_memset(mem, 'x', 50);
	ft_memset(mem, 'a', 10);
	for (int i = 0; i < 50; i++)
		printf("%c", mem[i]);
	printf("\n");
	//printf("%s\n", mem);
	return 0;
}
*/