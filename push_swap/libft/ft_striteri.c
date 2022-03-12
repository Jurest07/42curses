/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:24:08 by slight            #+#    #+#             */
/*   Updated: 2021/10/13 17:38:28 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	len_s;
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	len_s = ft_strlen(s);
	while (i < len_s)
	{
		f(i, &(s[i]));
		++i;
	}
}
