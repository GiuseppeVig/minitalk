/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigilan <gvigilan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:44:58 by gvigilan          #+#    #+#             */
/*   Updated: 2023/03/31 20:34:19 by gvigilan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*temp;

	if (lst == NULL)
		return (0);
	temp = ft_lstnew((f)(lst->content));
	if (temp == NULL)
		return (NULL);
	newlist = temp;
	lst = lst->next;
	while (lst != NULL)
	{
		temp = ft_lstnew((f)(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&lst, del);
			return (newlist);
		}
		ft_lstadd_back(&newlist, temp);
		lst = lst->next;
	}
	return (newlist);
}
