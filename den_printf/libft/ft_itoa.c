/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 02:58:10 by lis               #+#    #+#             */
/*   Updated: 2021/10/18 21:35:25 by akodos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*nvx_itoa_recursive(int n, int dp, int minus, int *len)
{
	char	digit;
	char	*s;

	digit = '0' - (n % 10);
	if (n / 10)
		s = nvx_itoa_recursive(n / 10, dp + 1, minus, len);
	else
	{
		*len = dp + 1 + minus;
		s = malloc(sizeof(char) * (*len + 1));
		if (s)
			s[*len] = '\0';
	}
	if (s)
		s[*len - 1 - dp] = digit;
	return (s);
}

char	*ft_itoa(int n)
{
	int		minus;
	int		len;
	char	*s;

	if (n < 0)
		minus = 1;
	else
	{
		minus = 0;
		n = -n;
	}
	s = nvx_itoa_recursive(n, 0, minus, &len);
	if (s && minus)
		s[0] = '-';
	return (s);
}
