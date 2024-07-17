/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:26:20 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/17 15:50:54 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		str_len;
	char	*new;

	str_len = ft_sstrlen(str);
	new = malloc(sizeof(char) * (str_len + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, str, str_len + 1);
	return (new);
}
/*
#include <stdio.h>

int	main()
{
	const char str[] = "bonjour emre";

	printf("%s", ft_strdup(str));
}
*/