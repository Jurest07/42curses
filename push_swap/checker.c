/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:49:05 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 21:59:18 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

char	*read_buff(void)
{
	char	*buff;
	char	*res;
	int		was_read;

	res = (char *)malloc(sizeof(*res));
	if (res == NULL)
		return (NULL);
	buff = (char *)malloc(sizeof(*buff) * 5);
	if (buff == NULL)
		return (NULL);
	res[0] = 0;
	was_read = read(0, buff, 4);
	buff[was_read] = 0;
	while (was_read != 0)
	{
		res = ft_strjoin(res, buff);
		was_read = read(0, buff, 4);
		buff[was_read] = 0;
	}
	free(buff);
	return (res);
}

void	check_buff(char *buff)
{
	int		i;
	int		j;
	char	str[4];

	i = 0;
	while (buff[i])
	{
		j = 0;
		while (buff[i] != '\n')
			str[j++] = buff[i++];
		str[j] = 0;
		if (!(check_str(str)))
		{
			exit (0);
		}
		++i;
	}
}

void	check_tmp(char *str, t_lists *lists)
{
	if (!(ft_memcmp(str, "ra", 3)))
		ra(&(lists->a), 2);
	if (!(ft_memcmp(str, "rb", 3)))
		rb(&(lists->b), 2);
	if (!(ft_memcmp(str, "sa", 3)))
		sa(&(lists->a), 2);
	if (!(ft_memcmp(str, "sb", 3)))
		sb(&(lists->b), 2);
	if (!(ft_memcmp(str, "ss", 3)))
		ss(&(lists->a), &(lists->b), 2);
	if (!(ft_memcmp(str, "rr", 3)))
		rr(&(lists->a), &(lists->b), 2);
	if (!(ft_memcmp(str, "rra", 4)))
		rra(&(lists->a), 2);
	if (!(ft_memcmp(str, "rrb", 4)))
		rrb(&(lists->b), 2);
	if (!(ft_memcmp(str, "rrr", 4)))
		rrr(&(lists->a), &(lists->b), 2);
	if (!(ft_memcmp(str, "pa", 3)))
		pa(&(lists->a), &(lists->b), 2);
	if (!(ft_memcmp(str, "pb", 3)))
		pb(&(lists->a), &(lists->b), 2);
}

t_bool	do_instructions(char *buff, t_lists *lists, int num)
{
	int		i;
	int		j;
	char	tmp[4];

	i = 0;
	while (buff[i])
	{
		j = 0;
		while (buff[i] != '\n' && buff[i])
			tmp[j++] = buff[i++];
		tmp[j] = 0;
		check_tmp(tmp, lists);
		++i;
	}
	find_max_sort(lists);
	if (lists->max_score_of_sort == num)
		return (TRUE);
	return (FALSE);
}

int	main(int argc, char *argv[])
{
	t_mainst	ps;
	t_lists		lists;
	char		*buff;

	if (argc == 1)
		exit(0);
	init_mainst(&ps);
	if (check_inputs(argc, argv, &ps) == FALSE)
		die("Error\n", 2);
	buff = read_buff();
	if (buff == NULL)
		exit (0);
	check_buff(buff);
	init_lists(&lists, argc, argv, &ps);
	if (do_instructions(buff, &lists, ps.c_ints))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	exit (0);
}
