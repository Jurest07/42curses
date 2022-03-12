/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_scores.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:23:56 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 20:53:28 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

int	count_of_rev(t_lists *lists)
{
	int	res;

	res = find_min_num(lists);
	if (res >= lists->numbers_in_a / 2)
		return (-(lists->numbers_in_a - res));
	return (res);
}

t_bool	check_min_and_max(t_lists *lists, int val)
{
	t_list_swap	*tmp_a;
	int			flag;

	flag = 0;
	tmp_a = lists->a;
	if (val < tmp_a->data)
	{
		while (tmp_a)
		{
			if (val > tmp_a->data)
				flag = 1;
			tmp_a = tmp_a->next;
		}
	}
	else
		clounada_with_check_min(lists, val, &flag);
	if (flag == 1)
		return (FALSE);
	return (TRUE);
}

int	find_score_iters_b(t_lists *lists, int *b_score)
{
	++*b_score;
	if (*b_score <= lists->numbers_in_b / 2)
		return (*b_score);
	else
		return (-(lists->numbers_in_b - *b_score));
}

int	find_score_iters_a2(t_lists *lists, int val)
{
	t_list_swap	*tmp_a;
	int			a_score;

	a_score = 0;
	tmp_a = lists->a;
	if (val > tmp_a->data)
	{
		while (val > tmp_a->data)
		{
			a_score += 1;
			tmp_a = tmp_a->next;
		}
		if (a_score >= lists->numbers_in_a / 2)
			a_score = -(lists->numbers_in_a - a_score);
		return (a_score);
	}
	return (a_score);
}

int	find_score_iters_a(t_lists *lists, int val)
{
	t_list_swap	*tmp_a;
	int			a_score;

	a_score = 0;
	if (check_min_and_max(lists, val))
		return (count_of_rev(lists));
	tmp_a = lists->a;
	if (val < tmp_a->data)
	{
		while (val < tmp_a->data)
		{
			a_score -= 1;
			tmp_a = getnth(lists->a, lists->numbers_in_a + a_score);
		}
		a_score += 1;
		if (a_score >= lists->numbers_in_a / 2)
			a_score = lists->numbers_in_a + a_score;
		return (a_score);
	}
	else
		a_score = find_score_iters_a2(lists, val);
	return (a_score);
}
