/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:14:00 by slight            #+#    #+#             */
/*   Updated: 2022/08/13 20:20:27 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	fun_pipe(t_info *info, char **invitation)
{
	push_back(&(info->jrs_list), PIPE, NULL);
	(*invitation)++;
}

void	fun_redir_insourse(t_info *info, char **invitation)
{
	push_back(&(info->jrs_list), REDIR_INSOURSE, NULL);
	*invitation = *invitation + 2;
}

void	fun_redir_append(t_info *info, char **invitation)
{
	push_back(&(info->jrs_list), REDIR_APPEND, NULL);
	*invitation = *invitation + 2;
}

void	fun_redir_in(t_info *info, char **invitation)
{
	push_back(&(info->jrs_list), REDIR_IN, NULL);
	(*invitation)++;
}

void	fun_redir_out(t_info *info, char **invitation)
{
	push_back(&(info->jrs_list), REDIR_OUT, NULL);
	(*invitation)++;
}
