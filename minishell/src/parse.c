/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 00:09:41 by slight            #+#    #+#             */
/*   Updated: 2022/08/10 14:58:52 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static bool	check_command_name(t_main_data *res, char *invitation)
{
	int		i;
	int		len;
	char	**lib_of_command;

	i = 0;
	lib_of_command = create_command_names();
	while (!(ft_strchr(SS, invitation[i])))
		i++;
	res->command_name = malloc(sizeof(char) * i + 1);
	len = i;
	i = 0;
	while (i < len)
	{
		res->command_name[i] = invitation[i];
		i++;
	}
	res->command_name[i] = '\0';
	i = 0;
	while (i < 7)
		if (ft_strcmp(res->command_name, lib_of_command[i++]))
			len = -1;
	clean_command_names(&lib_of_command);
	if (len == -1)
		return (false);
	return (true);
}

void	do_command(char *invitation, t_main_data *res)
{
	if (!check_command_name(res, invitation))
	{
		if (ft_strcmp(res->command_name, "echo"))
			do_echo(invitation);
		res->print_code = 1;
	}
	//final_print(res->print_code, res);
}
