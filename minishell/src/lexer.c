/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:08:14 by slight            #+#    #+#             */
/*   Updated: 2022/08/13 20:35:21 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	fun_word(t_info *info, char **invitation)
{
	int		len;
	int		i;
	char	*value;

	len = 0;
	i = 0;
	while (ft_strchr(WORDS, (*invitation)[len]))
		len++;
	value = malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		value[i] = (*invitation)[i];
		i++;
	}
	value[len] = '\0';
	push_back(&(info->jrs_list), WORD, value);
	*invitation = *invitation + len;
}

static void	fun_sep(t_info *info, char **invitation)
{
	while (**invitation == ' ')
	{
		(*invitation)++;
	}
	push_back(&(info->jrs_list), SEP, NULL);
}

static void	fun_field(t_info *info, char **invitation)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	(*invitation)++;
	while ((*invitation)[len] != '\'' && (*invitation)[len] != '\0')
		len++;
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	i = len;
	while (--len > -1)
		str[len] = (*invitation)[len];
	push_back(&(info->jrs_list), FIELD, str);
	if ((*invitation)[i] == '\0')
		*invitation = *invitation + i;
	else
		*invitation = *invitation + i + 1;
}

static void	fun_exp_field(t_info *info, char **invitation)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	(*invitation)++;
	while ((*invitation)[len] != '"' && (*invitation)[len] != '\0')
		len++;
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	i = len;
	while (--len > -1)
		str[len] = (*invitation)[len];
	push_back(&(info->jrs_list), EXP_FIELD, str);
	if ((*invitation)[i] == '\0')
		*invitation = *invitation + i;
	else
		*invitation = *invitation + i + 1;
}

void	lexer(t_info *info, char *invitation)
{
	while (*invitation != '\0')
	{
		if (*invitation == '|')
			fun_pipe(info, &invitation);
		else if (*invitation == '<' && *(invitation + 1) == '<')
			fun_redir_insourse(info, &invitation);
		else if (*invitation == '>' && *(invitation + 1) == '>')
			fun_redir_append(info, &invitation);
		else if (*invitation == '<')
			fun_redir_in(info, &invitation);
		else if (*invitation == '>')
			fun_redir_out(info, &invitation);
		else if (*invitation == '"')
			fun_exp_field(info, &invitation);
		else if (*invitation == '\'')
			fun_field(info, &invitation);
		else if (*invitation == ' ')
			fun_sep(info, &invitation);
		else if (*invitation == '$')
			fun_exp(info, &invitation);
		else
			fun_word(info, &invitation);
	}
}
