/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:56:06 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/28 15:09:14 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_LibftList	*ft_lstmap(t_LibftList *lst, void (*f)(void *), \
	void (*del)(void *))
{
	t_LibftList	*new;
	t_LibftList	*element;

	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	while (lst->next)
	{
		element = ft_lstnew(f(lst->next->content));
		if (!element)
			return (ft_lstclear(&new, del), NULL);
		ft_lstadd_back(&new, element);
		lst = lst->next;
	}
	return (new);
}
