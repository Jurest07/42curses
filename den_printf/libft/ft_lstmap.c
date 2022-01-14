/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:57:54 by lis               #+#    #+#             */
/*   Updated: 2022/01/11 13:53:24 by nvx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	**p;

	root = NULL;
	p = &root;
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
