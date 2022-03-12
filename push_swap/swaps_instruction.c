/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:24:27 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 20:54:22 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

void	sa(t_list_swap **a, int flag)
{
	t_list_swap	*tmp;

	tmp = (t_list_swap *)malloc(sizeof(t_list_swap));
	tmp->next = (*a)->next;
	(*a)->next = (*a)->next->next;
	tmp->next->next = *a;
	*a = tmp->next;
	if (flag == 0)
		write(1, "sa\n", 3);
	free (tmp);
}

void	sb(t_list_swap **b, int flag)
{
	t_list_swap	*tmp;

	tmp = (t_list_swap *)malloc(sizeof(t_list_swap));
	tmp->next = (*b)->next;
	(*b)->next = (*b)->next->next;
	tmp->next->next = *b;
	*b = tmp->next;
	if (flag == 0)
		write(1, "sb\n", 3);
	free (tmp);
}

void	ss(t_list_swap **a, t_list_swap **b, int flag)
{
	sa(a, 1);
	sb(b, 1);
	if (flag == 0)
		write(1, "ss\n", 3);
}
