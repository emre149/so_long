/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:49:35 by ededemog          #+#    #+#             */
/*   Updated: 2023/12/10 15:14:31 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int searchedChar, size_t n)
{
	unsigned char	*s;
	unsigned char	sc;
	size_t			i;

	i = 0;
	s = (unsigned char *)str;
	sc = (unsigned char)searchedChar;
	while (i < n)
	{
		if (s[i] == sc)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
