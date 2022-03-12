/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_rotate_instructions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:24:04 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 20:53:42 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pa(t_list_swap **a, t_list_swap **b, int flag)
{
	if (*b == NULL)
		return ;
	push(a, (*b)->data);
	pop(b);
	if (flag == 0)
		write(1, "pa\n", 3);
}

void	pb(t_list_swap **a, t_list_swap **b, int flag)
{
	if (*a == NULL)
		return ;
	push(b, (*a)->data);
	pop(a);
	if (flag == 0)
		write(1, "pb\n", 3);
}

void	ra(t_list_swap **a, int flag)
{
	t_list_swap	*tmp;

	tmp = getlast(*a);
	tmp->next = *a;
	*a = (*a)->next;
	tmp->next->next = NULL;
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rb(t_list_swap **b, int flag)
{
	t_list_swap	*tmp;

	tmp = getlast(*b);
	tmp->next = *b;
	*b = (*b)->next;
	tmp->next->next = NULL;
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rr(t_list_swap **a, t_list_swap **b, int flag)
{
	ra(a, 1);
	rb(b, 1);
	if (flag == 0)
		write(1, "rr\n", 3);
}
