/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:26:20 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/17 17:36:23 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	char	*s2;

	s2 = (char *)s;
	i = 0;
	while (s2[i])
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	return (ft_strdcpy(dest, s2));
}
