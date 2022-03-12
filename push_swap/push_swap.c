/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:24:10 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 21:55:36 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

void	free_lists(t_lists *lists)
{
	t_list_swap	*tmp;

	while (lists->a)
	{
		tmp = lists->a;
		lists->a = lists->a->next;
		free(tmp);
	}
	while (lists->b)
	{
		tmp = lists->b;
		lists->b = lists->b->next;
		free(tmp);
	}
	lists->a = NULL;
	lists->b = NULL;
}

int	main(int argc, char *argv[])
{
	t_mainst	ps;
	t_lists		lists;

	if (argc == 1)
		exit(0);
	init_mainst(&ps);
	if (check_inputs(argc, argv, &ps) == FALSE)
		die("Error\n", 2);
	init_lists(&lists, argc, argv, &ps);
	find_max_sort(&lists);
	if (lists.max_score_of_sort == ps.c_ints)
		exit (0);
	sort_iteration(&lists);
	free_lists(&lists);
	exit (0);
}
