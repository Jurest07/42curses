/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_on_ints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:47:06 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 21:56:13 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

t_bool	clounada_with_is_int(char *s, t_mainst *ps, int tmp, int start)
{
	while (s[tmp])
	{
		if (s[tmp] == ' ')
		{
			ps->c_ints_in_param += 1;
			while (s[tmp] == ' ')
				++tmp;
			start = tmp;
		}
		else if (ft_strchr(DIGITS, s[tmp]) == NULL)
			return (FALSE);
		else if (tmp != start && (s[tmp] == '-' || s[tmp] == '+'))
			return (FALSE);
		else if (tmp == start && s[tmp + 1] == '\0'
			&& (s[tmp] == '-' || s[tmp] == '+'))
			return (FALSE);
		else
			++tmp;
	}
	return (TRUE);
}

t_bool	is_int(char *s, t_mainst *ps)
{
	int	tmp;
	int	start_num_pos;

	tmp = 0;
	start_num_pos = tmp;
	ps->c_ints_in_param = 1;
	s = skip_spases_begin_end(s);
	if (clounada_with_is_int(s, ps, tmp, start_num_pos) == FALSE)
		return (FALSE);
	return (TRUE);
}

t_bool	check_on_ints(int coll, char *inputs[], t_mainst *ps)
{
	while (ps->iter < coll)
	{
		if (!is_int(inputs[ps->iter], ps))
			return (FALSE);
		++(ps->iter);
		ps->c_ints += ps->c_ints_in_param;
	}
	ps->iter = 1;
	return (TRUE);
}
