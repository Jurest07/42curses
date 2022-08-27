/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:42:31 by slight            #+#    #+#             */
/*   Updated: 2022/08/12 22:04:26 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static t_list	*get_last(t_list *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

void	push_back(t_list **head, int key, char *value)
{
	t_list	*last;
	t_list	*tmp;

	last = get_last(*head);
	if (last == NULL)
	{
		tmp = malloc(sizeof(t_list));
		tmp->key = key;
		tmp->value = value;
		tmp->next = (*head);
		*head = tmp;
	}
	else
	{
		tmp = malloc(sizeof(t_list));
		tmp->next = NULL;
		tmp->key = key;
		tmp->value = value;
		last->next = tmp;
	}
}
