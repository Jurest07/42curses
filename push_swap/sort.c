/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:24:19 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 20:54:13 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

t_bool	check_need_any_operations(t_lists *lists)
{
	int	max;

	max = lists->max_score_of_sort;
	find_max_sort(lists);
	if (lists->max_score_of_sort > max)
		return (TRUE);
	return (FALSE);
}

t_bool	check_of_need_sa(t_lists *lists)
{
	int	max;

	sa(&(lists->a), 1);
	max = lists->max_score_of_sort;
	find_max_sort(lists);
	if (lists->max_score_of_sort <= max)
	{
		sa(&(lists->a), 1);
		if (lists->pos_of_first != 0)
		{
			lists->pos_of_end -= 1;
			lists->pos_of_first -= 1;
		}
		return (FALSE);
	}
	sa(&(lists->a), 1);
	return (TRUE);
}

void	push_with_mediana(t_lists *lists)
{
	if (lists->all_numbers_count >= 10)
	{
		if (lists->a->data > lists->mediana && lists->b != NULL)
		{
			pb(&(lists->a), &(lists->b), 0);
			rb(&(lists->b), 0);
		}
		else
			pb(&(lists->a), &(lists->b), 0);
		lists->numbers_in_a -= 1;
	}
	else
	{
		pb(&(lists->a), &(lists->b), 0);
		lists->numbers_in_a -= 1;
	}
}

void	take_from_b(t_lists *lists)
{
	lists->numbers_in_b = lists->all_numbers_count - lists->numbers_in_a;
	while (lists->numbers_in_b != 0)
	{
		find_scores(lists);
		find_min_iters(lists);
		do_operations(lists);
		lists->numbers_in_b -= 1;
		lists->numbers_in_a += 1;
	}
}

void	sort_iteration(t_lists *lists)
{
	while (lists->pos_of_first != 0)
	{
		if (check_of_need_sa(lists))
		{
			sa(&(lists->a), 0);
		}
		else
			push_with_mediana(lists);
	}
	while (lists->pos_of_end != lists->numbers_in_a - 1)
	{
		rra(&(lists->a), 0);
		if (check_need_any_operations(lists))
			;
		else if (check_of_need_sa(lists))
			sa(&(lists->a), 0);
		else
			push_with_mediana(lists);
	}
	take_from_b(lists);
	final_reverse(lists);
}
