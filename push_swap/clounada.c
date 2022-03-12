/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clounada.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:56:58 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 20:52:09 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	clounada_with_check_min(t_lists *lists, int val, int *flag)
{
	t_list_swap	*tmp_a;

	tmp_a = lists->a;
	while (tmp_a)
	{
		if (val < tmp_a->data)
			*flag = 1;
		tmp_a = tmp_a->next;
	}
}

void	clounada_with_do_operations2(t_lists *lists)
{
	if (lists->iters_with_a <= 0)
	{
		while (lists->iters_with_a != 0)
		{
			rra(&(lists->a), 0);
			++lists->iters_with_a;
		}
	}
	if (lists->iters_with_b <= 0)
	{
		while (lists->iters_with_b != 0)
		{
			rrb(&(lists->b), 0);
			++lists->iters_with_b;
		}
	}
}

void	clounada_with_do_operations(t_lists *lists)
{
	if (lists->iters_with_a > 0)
	{
		while (lists->iters_with_a != 0)
		{
			ra(&(lists->a), 0);
			--lists->iters_with_a;
		}
	}
	if (lists->iters_with_b > 0)
	{
		while (lists->iters_with_b != 0)
		{
			rb(&(lists->b), 0);
			--lists->iters_with_b;
		}
	}
}
