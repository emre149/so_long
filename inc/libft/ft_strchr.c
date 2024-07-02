/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:57:09 by ededemog          #+#    #+#             */
/*   Updated: 2023/11/29 17:33:10 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int searchedChar)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((char)str[i] == (char)searchedChar)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	if ((char)searchedChar == (char)str[i])
		return ((char *)&str[i]);
	return (NULL);
}
