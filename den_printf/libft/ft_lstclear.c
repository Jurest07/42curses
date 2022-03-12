/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:08:33 by lis               #+#    #+#             */
/*   Updated: 2021/10/18 21:31:05 by akodos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*nxt;

	cur = *lst;
	while (cur)
	{
		nxt = cur->next;
		del(cur->content);
		free(cur);
		cur = nxt;
	}
	*lst = NULL;
}
