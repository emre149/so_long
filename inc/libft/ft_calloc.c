/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 01:32:15 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/28 15:19:11 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*var;

	if (size && count > 2147483647 / size)
		return (0);
	var = malloc(count * size);
	if (!var)
		return (0);
	ft_bzero(var, count * size);
	return (var);
}
