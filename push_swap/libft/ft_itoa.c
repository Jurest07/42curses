/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:31:48 by slight            #+#    #+#             */
/*   Updated: 2021/10/13 15:58:51 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	jrs_power(int osn, int st)
{
	if (st == 0)
		return (1);
	return (osn * jrs_power(osn, st - 1));
}

int	count_power(int n)
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

char	*create_res(int n, int p, int *pos)
{
	char	*res;

	if (n < 0)
	{
		res = malloc(sizeof(char) * (p + 2));
		if (res == NULL)
			return (NULL);
		*res = '-';
		++(*pos);
		++res;
	}
	else
	{
		res = malloc(sizeof(char) * (p + 1));
		if (res == NULL)
			return (NULL);
	}
	return (res);
}

char	*fill_res(int dell, int n, char *res, int pos)
{
	while (dell > 0)
	{
		*res = -(n / dell) + 48;
		++res;
		++pos;
		n = n % dell;
		dell = dell / 10;
	}
	*res = '\0';
	res = res - pos;
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		p;
	int		dell;
	int		pos;

	if (n == 0 || n == -0)
	{
		res = malloc(sizeof(char) * 2);
		res[0] = 48;
		res[1] = '\0';
		return (res);
	}
	pos = 0;
	p = count_power(n);
	res = create_res(n, p, &pos);
	if (res == NULL)
		return (NULL);
	dell = jrs_power(10, p - 1);
	if (n > 0)
		n = -n;
	res = fill_res(dell, n, res, pos);
	return (res);
}
