/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:05:23 by ededemog          #+#    #+#             */
/*   Updated: 2023/11/28 16:40:35 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char	*dest_temp;
	unsigned char	*src_temp;

	if (size == 0 && !dest)
		return (NULL);
	dest_temp = (unsigned char *)dest;
	src_temp = (unsigned char *)src;
	while (size > 0)
	{
		*(dest_temp++) = *(src_temp++);
		size--;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "";
    char destination[0];

    // Utilisez votre fonction my_memcpy ici
    ft_memcpy(destination, source, ft_strlen(source) + 1);
	memcpy(destination, source, ft_strlen(source) + 1);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}
*/