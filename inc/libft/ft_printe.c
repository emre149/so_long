/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:47:40 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/25 16:02:05 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


static int	redirect(const char c, va_list vl, int fd)
{
	int	rt;

	rt = 0;
	if (c == 'c')
		rt = ft_putchar_fd(va_arg(vl, int), fd);
	else if (c == 's')
		rt = ft_putstr_fd(va_arg(vl, char *), fd);
	else if (c == 'p')
	{
		rt = ft_putstr_fd("0x", fd);
		if (rt == -1)
			return (rt);
		rt += ft_putnbr_b_fd(va_arg(vl, unsigned long), "0123456789abcdef", fd);
	}
	else if (c == 'd' || c == 'i')
		rt = ft_putnbr_fd(va_arg(vl, long int), fd);
	else if (c == 'u')
		rt = ft_putnbr_b_fd(va_arg(vl, unsigned int), "0123456789", fd);
	else if (c == 'x')
		rt = ft_putnbr_b_fd(va_arg(vl, unsigned int), "0123456789abcdef", fd);
	else if (c == 'X')
		rt = ft_putnbr_b_fd(va_arg(vl, unsigned int), "0123456789ABCDEF", fd);
	else if (c == '%')
		rt = ft_putchar_fd('%', fd);
	return (rt);
}

int	ft_printf_e(const char *s, ...)
{
	va_list	vl;
	int		rt_val;
	int		i;
	int		tmp;

	va_start(vl, s);
	i = -1;
	tmp = 0;
	rt_val = 0;
	if (write(1, 0, 0) != 0)
		return (-1);
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			tmp = redirect(s[++i], vl, 1);
			if (tmp == -1)
				return (-1);
			rt_val += tmp;
		}
		else if (s[i] != '%')
			rt_val += ft_putchar_fd(s[i], 2);
	}
	va_end(vl);
	return (rt_val);
}
