/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:18:59 by slight            #+#    #+#             */
/*   Updated: 2022/08/14 18:32:51 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main(void)
{
	char		*str_invitation;
	t_info		info;

	info.jrs_list = NULL;
	while (1)
	{
		str_invitation = readline("jrsshell$ ");
		lexer(&info, str_invitation);
		while (info.jrs_list != NULL)
		{
			printf("%d : %s\n", info.jrs_list->key, info.jrs_list->value);
			info.jrs_list = info.jrs_list->next;
		}
		printf("\n");
		//parser(&info);
	}
	return (0);
}
