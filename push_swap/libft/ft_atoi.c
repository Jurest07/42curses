/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:50:05 by slight            #+#    #+#             */
/*   Updated: 2022/03/05 00:33:54 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

const char	*skip_spases(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\n' || *str == '\f' || *str == '\r')
		++str;
	return (str);
}

int	check_first(const char *str)
{
	if ((*str >= 48 && *str <= 57) || *str == 45 || *str == 43)
		return (0);
	return (1);
}

long	convertation(const char *str, int *minus)
{
	long	s;

	s = 0;
	if (*str == 45)
		*minus = 1;
	if (*str == 45 || *str == 43)
		++str;
	while (*str >= 48 && *str <= 57)
	{
		if (s <= -922337203685477580 && (*str - 48) > 7 && *minus == 0)
			return (-9223372036854775807);
		if (s <= -922337203685477580 && *minus == 1 && (*str - 48) > 7)
			return (9223372036854775801);
		s = s * 10 - (*str - 48);
		++str;
	}
	return (s);
}

long	ft_atoi(const char *str)
{
	int		minus;
	long	res;

	res = 0;
	minus = 0;
	str = skip_spases(str);
	if (check_first(str))
		return (0);
	res = convertation(str, &minus);
	if (minus == 0)
		res = -res;
	return (res);
}
