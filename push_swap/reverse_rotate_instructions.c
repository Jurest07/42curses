/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:24:13 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 20:53:49 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list_swap	*getlastlast(t_list_swap *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next->next)
		head = head->next;
	return (head);
}

void	rra(t_list_swap **a, int flag)
{
	t_list_swap	*tmp;
	t_list_swap	*prev;

	tmp = getlast(*a);
	prev = getlastlast(*a);
	tmp->next = *a;
	*a = tmp;
	prev->next = NULL;
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_list_swap **b, int flag)
{
	t_list_swap	*tmp;
	t_list_swap	*prev;

	tmp = getlast(*b);
	prev = getlastlast(*b);
	tmp->next = *b;
	*b = tmp;
	prev->next = NULL;
	if (flag == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_list_swap **a, t_list_swap **b, int flag)
{
	rra(a, 1);
	rrb(b, 1);
	if (flag == 0)
		write(1, "rrr\n", 4);
}
