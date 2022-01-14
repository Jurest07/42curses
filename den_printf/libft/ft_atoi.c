/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:58 by lis               #+#    #+#             */
/*   Updated: 2021/10/07 00:19:54 by lis              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	nvx_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(char const *str)
{
	int	res;
	int	isneg;

	isneg = 0;
	while (nvx_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			isneg = 1;
		++str;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
		res = res * 10 - (*str++ - '0');
	if (!isneg)
		res = -res;
	return ((int)res);
}
