/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:24:21 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/17 15:49:52 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;
	size_t			len_s;

	if (!s)
		return (NULL);
	len_s = ft_sstrlen(s);
	if (start > len_s)
		return (ft_strdup(""));
	if ((len + start) > len_s)
		len = ft_sstrlen(s) - start;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = start;
	while (s[i] && i - start < len)
	{
		new[i - start] = s[i];
		i++;
	}
	new[i - start] = '\0';
	return ((char *)new);
}
