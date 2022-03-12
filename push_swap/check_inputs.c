/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:46:57 by slight            #+#    #+#             */
/*   Updated: 2022/03/12 15:39:13 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

t_bool	check_inputs(int coll, char *inputs[], t_mainst *ps)
{
	int	i;

	i = 1;
	while (i < coll)
		if (inputs[i] == NULL || inputs[i++][0] == '\0')
			return (FALSE);
	if (!check_on_ints(coll, inputs, ps))
		return (FALSE);
	if (!check_maxmin_and_equal(coll, inputs, ps))
		return (FALSE);
	return (TRUE);
}
