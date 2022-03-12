/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:23:30 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 20:53:12 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

void	do_operations4(t_lists *lists)
{
	if (lists->iters_with_a > 0 && lists->iters_with_b < 0)
	{
		while (lists->iters_with_a != 0)
		{
			ra(&(lists->a), 0);
			--lists->iters_with_a;
		}
		while (lists->iters_with_b != 0)
		{
			rrb(&(lists->b), 0);
			++lists->iters_with_b;
		}
		pa(&(lists->a), &(lists->b), 0);
	}
}

void	do_operations3(t_lists *lists)
{
	if (lists->iters_with_a < 0 && lists->iters_with_b > 0)
	{
		while (lists->iters_with_a != 0)
		{
			rra(&(lists->a), 0);
			++lists->iters_with_a;
		}
		while (lists->iters_with_b != 0)
		{
			rb(&(lists->b), 0);
			--lists->iters_with_b;
		}
		pa(&(lists->a), &(lists->b), 0);
	}
	else
		do_operations4(lists);
}

void	do_operations2(t_lists *lists)
{
	if (lists->iters_with_a <= 0 && lists->iters_with_b <= 0)
	{
		while (lists->iters_with_a != 0 && lists->iters_with_b != 0)
		{
			rrr(&(lists->a), &(lists->b), 0);
			++lists->iters_with_a;
			++lists->iters_with_b;
		}
		clounada_with_do_operations2(lists);
		pa(&(lists->a), &(lists->b), 0);
	}
	else
		do_operations3(lists);
}

void	do_operations(t_lists *lists)
{
	if (lists->iters_with_a >= 0 && lists->iters_with_b >= 0)
	{
		while (lists->iters_with_a != 0 && lists->iters_with_b != 0)
		{
			rr(&(lists->a), &(lists->b), 0);
			--lists->iters_with_a;
			--lists->iters_with_b;
		}
		clounada_with_do_operations(lists);
		pa(&(lists->a), &(lists->b), 0);
	}
	else
		do_operations2(lists);
}
