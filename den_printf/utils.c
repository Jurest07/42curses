/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 19:31:27 by lis               #+#    #+#             */
/*   Updated: 2021/11/08 21:49:36 by nvx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "accessory.h"
#include "libft/libft.h"

int	min_i(int a, int b)
{
	if (b < a)
		return (b);
	return (a);
}

long long	absll(long long val)
{
	if (val < 0)
		return (-val);
	return (val);
}

t_bool	addret(int val, int *sum)
{
	if (val < 0)
		return (FALSE);
	*sum += val;
	return (TRUE);
}

int	sumret(int val, int sum)
{
	if (val < 0)
		return (-1);
	return (val + sum);
}

void	extract_value(t_place *pl, va_list args)
{
	if (pl->fmt == 'c')
		pl->v.c = (char)va_arg(args, int);
	else if (pl->fmt == 's')
		pl->v.s = (char *)va_arg(args, char *);
	else if (pl->fmt == 'p')
		pl->v.p = (void *)va_arg(args, void *);
	else if (ft_strchr("uxX", pl->fmt))
		pl->v.u = (unsigned int)va_arg(args, unsigned int);
	else if (ft_strchr("di", pl->fmt))
		pl->v.i = (int)va_arg(args, int);
}
