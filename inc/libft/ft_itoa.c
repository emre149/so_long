/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:59:00 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/28 15:18:58 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits(long int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (0);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	int		i;
	char	*new;

	nb = n;
	i = len -1;
	len = digits(n);
	new = malloc(sizeof(char) * (len + (n < 0) + 1));
	if (!new)
		return (NULL);
	if (n < 0)
	{
		new[0] = '-';
		nb = -nb;
	}
	new[len + (n < 0)] = '\0';
	while (nb > 0)
	{
		new[i--] = nb % 10 + '0';
		nb /= 10;
	}
	if (n == 0)
		new[0] = '0';
	return (new);
}
