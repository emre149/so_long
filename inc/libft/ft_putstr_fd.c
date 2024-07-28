/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:24:37 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/28 15:10:09 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *str, int fd)
{
	size_t	i;
	int		rt_val;

	i = 0;
	rt_val = 0;
	if (!str)
		i = ft_putstr_fd("(null)", fd);
	else
	{
		while (str[i])
		{
			rt_val = ft_putchar_fd(str[i++], fd);
			if (rt_val == -1)
				return (rt_val);
		}
	}
	return (i);
}
