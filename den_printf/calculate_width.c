/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lis <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:01:02 by lis               #+#    #+#             */
/*   Updated: 2022/01/11 14:41:45 by nvx              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "accessory.h"
#include "libft/libft.h"

static int	calculate_integer_rigwidth(t_ullong v, int base)
{
	int	n;

	n = 1;
	v /= base;
	while (v)
	{
		++n;
		v /= base;
	}
	return (n);
}

static void	calculate_rigwidth(t_place *pl)
{
	if (pl->fmt == 'i' || pl->fmt == 'd')
		pl->rigwidth = calculate_integer_rigwidth(absll(pl->v.i), 10);
	else if (pl->fmt == 'u')
		pl->rigwidth = calculate_integer_rigwidth(pl->v.u, 10);
	else if (pl->fmt == 'x' || pl->fmt == 'X')
		pl->rigwidth = calculate_integer_rigwidth(pl->v.u, 16);
	else if (pl->fmt == 'p')
		pl->rigwidth = calculate_integer_rigwidth((t_ullong)pl->v.p, 16);
	else if (pl->fmt == 'c')
		pl->rigwidth = 1;
	else if (pl->fmt == 's')
	{
		if (pl->v.s)
			pl->rigwidth = ft_strlen(pl->v.s);
		else
			pl->rigwidth = 6;
		if (pl->prec >= 0 && pl->prec < pl->rigwidth)
			pl->rigwidth = pl->prec;
	}
}

static void	calculate_sftwidth(t_place *pl)
{
	if (pl->prec > pl->rigwidth)
		pl->sftwidth = pl->prec;
	else
		pl->sftwidth = pl->rigwidth;
	if (ft_strchr("id", pl->fmt))
	{
		if (pl->v.i < 0 || pl->flags & (SIGN_BEFORE | SPACE_BEFORE))
			pl->sftwidth += 1;
	}
	else if (pl->fmt == 'p')
	{
		pl->sftwidth += 2;
		if (pl->flags & (SIGN_BEFORE | SPACE_BEFORE))
			pl->sftwidth += 1;
	}
	else if (ft_strchr("xX", pl->fmt) && pl->flags & SPECIAL_FORMAT)
		pl->sftwidth += 2;
}

void	calculate_width_params(t_place *pl)
{
	calculate_rigwidth(pl);
	calculate_sftwidth(pl);
}
