/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_function2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:58:55 by slight            #+#    #+#             */
/*   Updated: 2022/08/14 12:11:21 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	fun_exp2(t_info *info, char **invitation)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	(*invitation)++;
	while ((*invitation)[len] != ' ' && (*invitation)[len] != '\0')
		len++;
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	i = len;
	while (--len > -1)
		str[len] = (*invitation)[len];
	push_back(&(info->jrs_list), EXP, str);
	*invitation = *invitation + i;
}

void	fun_exp(t_info *info, char **invitation)
{
	if (*(*invitation + 1) == '?')
	{
		push_back(&(info->jrs_list), STATUS, NULL);
		*invitation = *invitation + 2;
	}
	else
		fun_exp2(info, invitation);
}
