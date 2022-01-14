/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:41:07 by slight            #+#    #+#             */
/*   Updated: 2022/01/14 19:01:29 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_len(int osn, t_ull num)
{
	int	dell;

	if (num == 0)
		return (1);
	dell = 0;
	while (num > 0)
	{
		num /= osn;
		++dell;
	}
	return (dell);
}

int	digit_count_of_int(int n)
{
	int	p;

	p = 0;
	while (n != 0)
	{
		n = n / 10;
		++p;
	}
	return (p);
}

int	digit_count_of_ui(t_ui n)
{
	int	p;

	p = 0;
	while (n != 0)
	{
		n = n / 10;
		++p;
	}
	return (p);
}

t_ull	jrs_power(int osn, int st)
{
	if (st == 0)
		return (1);
	return (osn * jrs_power(osn, st - 1));
}
