/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_iters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:23:47 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 20:53:21 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

void	find_scores(t_lists *lists)
{
	t_list_swap	*tmp_b;
	int			b_score;

	b_score = -1;
	tmp_b = lists->b;
	while (tmp_b)
	{
		tmp_b->a_source = find_score_iters_a(lists, tmp_b->data);
		tmp_b->b_source = find_score_iters_b(lists, &b_score);
		tmp_b = tmp_b->next;
	}
}

void	find_min_iters(t_lists *lists)
{
	t_list_swap	*tmp_b;
	int			min;

	tmp_b = lists->b->next;
	lists->iters_with_a = lists->b->a_source;
	lists->iters_with_b = lists->b->b_source;
	min = ft_abs(calc_sum_iters(lists->iters_with_a, lists->iters_with_b));
	while (tmp_b)
	{
		if (ft_abs(calc_sum_iters(tmp_b->a_source, tmp_b->b_source)) < min)
		{
			min = ft_abs(calc_sum_iters(tmp_b->a_source, tmp_b->b_source));
			lists->iters_with_a = tmp_b->a_source;
			lists->iters_with_b = tmp_b->b_source;
		}
		tmp_b = tmp_b->next;
	}
}

void	do_reverse(t_lists *lists)
{
	if (lists->pos_of_first <= lists->all_numbers_count / 2)
	{
		while (lists->pos_of_first != 0)
		{
			ra(&(lists->a), 0);
			lists->pos_of_first -= 1;
		}
	}
	else
	{
		while (lists->pos_of_first != lists->all_numbers_count)
		{
			rra(&(lists->a), 0);
			lists->pos_of_first += 1;
		}
	}
}

void	final_reverse(t_lists *lists)
{
	t_list_swap	*tmp_a;

	tmp_a = lists->a->next;
	lists->pos_of_first = 0;
	lists->iter = 0;
	lists->val_of_first = lists->a->data;
	while (tmp_a)
	{
		lists->iter += 1;
		if (tmp_a->data < lists->val_of_first)
		{
			lists->val_of_first = tmp_a->data;
			lists->pos_of_first = lists->iter;
		}
		tmp_a = tmp_a->next;
	}
	do_reverse(lists);
}
