/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_and_min.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:44:57 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 21:53:55 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

void	free_mas(char **mas, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free((mas[i]));
		++i;
	}
	free(mas);
}

int	numbers_in_str(char *s)
{
	int	i;
	int	num;

	i = 0;
	num = 1;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			++num;
			while (s[i] == ' ')
				i++;
		}
		else
			i++;
	}
	return (num);
}

t_bool	check_string(char *s, long tmp[], int *t)
{
	int		num;
	char	**mas;
	int		i;

	i = 0;
	s = skip_spases_begin_end(s);
	num = numbers_in_str(s);
	mas = ft_split(s, ' ');
	if (mas == NULL)
		return (FALSE);
	while (i < num)
	{
		tmp[*t] = ft_atoi(mas[i]);
		if (tmp[*t] > MAXINT || tmp[*t] < MININT)
		{
			free_mas(mas, num);
			return (FALSE);
		}
		++(*t);
		++i;
	}
	free_mas(mas, i);
	return (TRUE);
}

t_bool	check_equal(long numbers[], int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (FALSE);
			++j;
		}
		++i;
	}
	return (TRUE);
}

t_bool	check_maxmin_and_equal(int coll, char *inputs[], t_mainst *ps)
{
	long	*tmp;
	int		t;

	t = 0;
	tmp = malloc(sizeof(long) * ps->c_ints);
	if (tmp == NULL)
		die("malloc error", 2);
	while (ps->iter < coll)
	{
		if (!check_string(inputs[ps->iter], tmp, &t))
		{
			free(tmp);
			return (FALSE);
		}
		++(ps->iter);
	}
	if (!check_equal(tmp, ps->c_ints))
	{
		free(tmp);
		return (FALSE);
	}
	ps->iter = 1;
	free(tmp);
	return (TRUE);
}
