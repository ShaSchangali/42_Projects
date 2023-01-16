/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:52:10 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:52:12 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_a_or_b(t_list **a)
{
	t_list	*tmp;
	t_list	*head;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a);
	head = (*a)->next->next;
	*a = (*a)->next;
	(*a)->next = tmp;
	tmp->next = head;
}

void	push_a_or_b(t_list	**n1, t_list **n2)
{
	t_list	*head;

	if (!(*n1))
		return ;
	head = *n1;
	*n1 = head->next;
	if (*n2)
		head->next = (*n2);
	else
		head->next = NULL;
	*n2 = head;
}

void	rotate_top_becomes_last(t_list **head)
{
	t_list	*top;
	t_list	*last;

	if (!(*head) || !(*head)->next)
		return ;
	top = *head;
	*head = (*head)->next;
	last = (*head);
	while (last->next)
		last = last->next;
	last->next = top;
	top->next = NULL;
}

void	reverse_rotate_last_becomes_first(t_list **head)
{
	t_list	*first;
	t_list	*last;

	if (!(*head) || !(*head)->next)
		return ;
	last = (*head);
	while (last->next)
	{
		first = last;
		last = last->next;
	}
	last->next = (*head);
	*head = last;
	first->next = NULL;
}
