/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:56:06 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/17 14:49:09 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

LibFt_t_list	*ft_lstmap(LibFt_t_list *lst, void (*f)(void *), void (*del)(void *))
{
	LibFt_t_list	*new;
	LibFt_t_list	*element;

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
