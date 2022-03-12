/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:39:04 by slight            #+#    #+#             */
/*   Updated: 2021/10/26 19:28:46 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void(*del)(void *))
{
	t_list	*root;
	t_list	**p;

	root = NULL;
	p = &root;
	(void)del;
	while (lst)
	{
		*p = ft_lstnew(f(lst->content));
		if (!*p)
		{
			ft_lstclear(&root, del);
			return (NULL);
		}
		p = &(*p)->next;
		lst = lst->next;
	}
	return (root);
}
