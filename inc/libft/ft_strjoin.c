/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:25:38 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/17 17:06:59 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_totalsize(char const *s1, char const *s2)
{
	int	res;

	res = 0;
	res += ft_sstrlen((char *)s1);
	res += ft_sstrlen((char *)s2);
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	str = malloc((ft_totalsize((char *)s1, (char *)s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	ft_strcat(str, (char *)s1);
	ft_strcat(str, (char *)s2);
	return (str);
}
