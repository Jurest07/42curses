/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:24:02 by slight            #+#    #+#             */
/*   Updated: 2022/03/10 20:53:39 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push(t_list_swap **head, int data)
{
	t_list_swap	*tmp;

	tmp = (t_list_swap *)malloc(sizeof(t_list_swap));
	tmp->data = data;
	tmp->next = *head;
	*head = tmp;
}

int	pop(t_list_swap **head)
{
	t_list_swap	*prev;
	int			val;

	prev = NULL;
	if (head == NULL)
	{
		exit(0);
	}
	prev = (*head);
	val = prev->data;
	(*head) = (*head)->next;
	free(prev);
	return (val);
}

t_list_swap	*getnth(t_list_swap *head, int n)
{
	int	counter;

	counter = 0;
	while (counter < n && head)
	{
		head = head->next;
		counter++;
	}
	return (head);
}

t_list_swap	*getlast(t_list_swap *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	pushback(t_list_swap *head, int data)
{
	t_list_swap	*last;
	t_list_swap	*tmp;

	last = getlast(head);
	tmp = (t_list_swap *) malloc(sizeof(t_list_swap));
	tmp->data = data;
	tmp->next = NULL;
	last->next = tmp;
}
