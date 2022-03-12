/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:52:41 by slight            #+#    #+#             */
/*   Updated: 2021/10/13 16:02:21 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len_of_list;

	len_of_list = 0;
	while (lst != NULL)
	{
		++len_of_list;
		lst = lst->next;
	}
	return (len_of_list);
}
