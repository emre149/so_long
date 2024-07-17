/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:59:43 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/17 14:47:27 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

LibFt_t_list	*ft_lstlast(LibFt_t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
