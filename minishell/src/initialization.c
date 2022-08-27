/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 01:16:10 by slight            #+#    #+#             */
/*   Updated: 2022/08/10 13:09:11 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	init_main_data(t_main_data *res)
{
	res->command_name = NULL;
	res->absulut_path = NULL;
	res->relative_path = NULL;
	res->file_name = NULL;
	res->count_pipes = 0;
	res->count_in = 0;
	res->count_out = 0;
	res->count_inin = 0;
	res->count_outout = 0;
	res->count_variables = 0;
	res->invitation_len = 0;
	res->print_code = 0;
}

void	clean_main_data(t_main_data *res)
{
	free(res->command_name);
	if (res->absulut_path != NULL)
		free(res->absulut_path);
	if (res->relative_path != NULL)
		free(res->relative_path);
	if (res->file_name != NULL)
		free(res->file_name);
	res->count_pipes = 0;
	res->count_in = 0;
	res->count_out = 0;
	res->count_inin = 0;
	res->count_outout = 0;
	res->count_variables = 0;
	res->invitation_len = 0;
	res->print_code = 0;
}

char	**create_command_names(void)
{
	char	**lib_of_command_names;

	lib_of_command_names = malloc(sizeof(char *) * 7);
	lib_of_command_names[0] = "echo";
	lib_of_command_names[1] = "cd";
	lib_of_command_names[2] = "pwd";
	lib_of_command_names[3] = "export";
	lib_of_command_names[4] = "unset";
	lib_of_command_names[5] = "env";
	lib_of_command_names[6] = "exit";
	return (lib_of_command_names);
}

void	clean_command_names(char ***lib)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		(*lib)[i] = NULL;
		i++;
	}
	free(*lib);
}
