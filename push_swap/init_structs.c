/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:23:59 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 20:53:34 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	init_score_a(t_score_a *sca)
{
	sca->a_score = 0;
	sca->ff = 0;
	sca->flag = 0;
	sca->pred = 0;
}

void	init_mainst(t_mainst *ps)
{
	ps->c_ints = 0;
	ps->c_ints_in_param = 0;
	ps->iter = 1;
}

void	init_simple_lists(t_lists *lists, int med, int count)
{
	lists->b = NULL;
	lists->max_score_of_sort = 0;
	lists->pos_of_first = 0;
	lists->pos_of_end = 0;
	lists->val_of_end = 0;
	lists->val_of_first = 0;
	lists->iter = 0;
	lists->all_numbers_count = count;
	lists->numbers_in_a = count;
	lists->mediana = med;
	lists->numbers_in_b = 0;
	lists->iters_with_a = 0;
	lists->iters_with_b = 0;
}

void	init_lists(t_lists *lists, int argc, char *argv[], t_mainst *ps)
{
	long	*numbers;
	int		t;
	int		med;

	t = 0;
	numbers = malloc(sizeof(long) * ps->c_ints);
	if (numbers == NULL)
		die("malloc error", 2);
	while (ps->iter < argc)
	{
		check_string(argv[ps->iter], numbers, &t);
		++(ps->iter);
	}
	lists->a = NULL;
	push(&(lists->a), (int) numbers[0]);
	t = 1;
	while (t < ps->c_ints)
	{
		pushback(lists->a, (int) numbers[t]);
		++t;
	}
	med = calc_med(numbers, ps->c_ints);
	init_simple_lists(lists, med, ps->c_ints);
	free(numbers);
}
