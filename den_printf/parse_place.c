/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <lis@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:32:24 by lis               #+#    #+#             */
/*   Updated: 2022/01/11 17:34:56 by nvx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "accessory.h"
#include "libft/libft.h"

static int	flag_to_digit(char c)
{
	if (c == '#')
		return (SPECIAL_FORMAT);
	if (c == '0')
		return (ZERO_PADDED);
	if (c == '-')
		return (LEFT_ADJUSTED);
	if (c == ' ')
		return (SPACE_BEFORE);
	if (c == '+')
		return (SIGN_BEFORE);
	return (-1);
}

static int	parse_number(char const **p)
{
	int	res;

	res = 0;
	while (ft_isdigit(**p))
		res = res * 10 + (*(*p)++ - '0');
	return (res);
}

/*
 * Pointer p must be placed after percent;
 * double percent must been handled before call of
 * this function
 */
t_bool	parse_place(char const **p, t_place *pl)
{
	char const	*save;

	save = *p;
	pl->flags = 0;
	pl->minwidth = 0;
	pl->prec = -1;
	while (ft_strchr(AVALIABLE_FLAGS, **p))
		pl->flags |= flag_to_digit(*(*p)++);
	if (ft_isdigit(**p))
		pl->minwidth = parse_number(p);
	if (**p == '.')
	{
		++*p;
		pl->prec = parse_number(p);
		pl->flags &= ~ZERO_PADDED;
	}
	if (!ft_strchr(AVALIABLE_FORMATS, **p))
	{
		*p = save;
		return (FALSE);
	}
	pl->fmt = *(*p)++;
	return (TRUE);
}
