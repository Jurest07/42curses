/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:24:16 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 20:53:52 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

char	*skip_spases_begin_end(char *s)
{
	int	len;

	len = ft_strlen(s);
	while (s[len - 1] == ' ')
		--len;
	s[len] = '\0';
	while (*s == ' ')
		++s;
	return (s);
}
