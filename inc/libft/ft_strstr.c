/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:39:54 by ededemog          #+#    #+#             */
/*   Updated: 2023/12/10 15:20:15 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *haystack, char *needle)
{
	int		i;
	char	*temp;

	temp = haystack;
	if (!*needle)
		return (haystack);
	while (*temp)
	{
		i = 0;
		if (*temp == needle[0])
		{
			while (temp[i] == needle[i] && needle[i])
				i++;
			if (needle[i] == '\0')
				return (temp);
		}
		temp++;
	}
	return (0);
}
