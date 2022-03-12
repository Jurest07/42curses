/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:24:23 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 21:53:41 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h> 

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	calc_med(long numbers[], int coll)
{
	long long	sum;
	int			i;
	int			res;

	i = 0;
	sum = 0;
	while (i < coll)
		sum += numbers[i++];
	res = sum / coll;
	return (res);
}

int	calc_sum_iters(int a, int b)
{
	if ((a >= 0 && b <= 0) || (a <= 0 && b >= 0))
		return (abs(a) + abs(b));
	else if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (a > 0 && b > 0 && a > b)
			return (a);
		else if (a > 0 && b > 0 && b >= a)
			return (b);
		else if (a < 0 && b < 0 && a < b)
			return (a);
		else
			return (b);
	}
	return (0);
}

int	find_min_num(t_lists *lists)
{
	t_list_swap	*tmp_a;
	int			res;
	int			num;

	res = 0;
	lists->pos_of_first = 0;
	tmp_a = lists->a->next;
	num = lists->a->data;
	while (tmp_a)
	{
		++res;
		if (tmp_a->data < num)
		{
			num = tmp_a->data;
			lists->pos_of_first = res;
		}
		tmp_a = tmp_a->next;
	}
	return (lists->pos_of_first);
}

t_bool	check_str(char *str)
{
	if (!(ft_memcmp(str, "ra", 3)))
		return (TRUE);
	if (!(ft_memcmp(str, "rb", 3)))
		return (TRUE);
	if (!(ft_memcmp(str, "sa", 3)))
		return (TRUE);
	if (!(ft_memcmp(str, "sb", 3)))
		return (TRUE);
	if (!(ft_memcmp(str, "ss", 3)))
		return (TRUE);
	if (!(ft_memcmp(str, "rr", 3)))
		return (TRUE);
	if (!(ft_memcmp(str, "pa", 3)))
		return (TRUE);
	if (!(ft_memcmp(str, "pb", 3)))
		return (TRUE);
	if (!(ft_memcmp(str, "rra", 4)))
		return (TRUE);
	if (!(ft_memcmp(str, "rrb", 4)))
		return (TRUE);
	if (!(ft_memcmp(str, "rrr", 4)))
		return (TRUE);
	return (FALSE);
}
