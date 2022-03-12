/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:23:44 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 20:53:18 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

void	find_vals(t_lists *lists)
{
	t_list_swap	*tmp;
	int			i;

	i = 0;
	tmp = lists->a;
	while (tmp)
	{
		if (i == lists->pos_of_first)
			lists->val_of_first = tmp->data;
		if (i == lists->pos_of_end)
			lists->val_of_end = tmp->data;
		tmp = tmp->next;
		++i;
	}
}

void	sort2(int prev, t_list_swap *temp, int *tmp, t_lists *lists)
{
	if (prev < temp->data)
		++(*tmp);
	else
	{
		if (lists->max_score_of_sort <= *tmp)
		{
			lists->max_score_of_sort = *tmp;
			lists->pos_of_end = lists->iter;
			lists->pos_of_first = lists->iter - *tmp + 1;
		}
		*tmp = 1;
	}
}

void	find_max_sort(t_lists *lists)
{
	t_list_swap	*temp;
	int			tmp;
	int			prev;

	tmp = 1;
	prev = lists->a->data;
	temp = lists->a->next;
	lists->iter = 0;
	while (temp)
	{
		sort2(prev, temp, &tmp, lists);
		++(lists->iter);
		prev = temp->data;
		temp = temp->next;
	}
	if (lists->max_score_of_sort <= tmp)
	{
		lists->max_score_of_sort = tmp;
		lists->pos_of_end = lists->iter;
		lists->pos_of_first = lists->iter - tmp + 1;
	}
	find_vals(lists);
}
