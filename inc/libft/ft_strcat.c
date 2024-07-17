/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:49:49 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/17 17:06:51 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	dest_length;
	int	i;

	dest_length = ft_sstrlen(dest);
	i = 0;
	while (src[i])
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (dest);
}

/*
#include <stdio.h>

int	main()
{
	char s1[100] = "bonjour ";
	char s2[100] = "emre";

	printf("%s", ft_strcat(s1, s2));
}
*/