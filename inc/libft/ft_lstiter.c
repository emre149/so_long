/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:56:51 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/28 15:08:38 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_LibftList *lst, void (*f)(void *))
{
	t_LibftList	*temp;

	temp = lst;
	if (lst && f)
	{
		while (temp)
		{
			f(temp->content);
			temp = temp->next;
		}
	}
}
