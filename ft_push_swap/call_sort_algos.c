/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_sort_algos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:48:59 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 02:04:18 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_algo_2n(t_struct *head, int size)
{
	if (is_sorted(head) == TRUE)
		return ;
	if (size == 2)
		sorting_algo_2n(head);
}

void	call_algo_3n(t_struct *head, int size)
{
	if (is_sorted(head) == TRUE)
		return ;
	if (size == 3)
		sorting_algo_3n(head);
}

void	call_algo_4n(t_struct *head, int size)
{
	if (is_sorted(head) == TRUE)
		return ;
	if (size == 4)
		sorting_algo_4n(head);
}

void	call_algo_5n(t_struct *head, int size)
{
	if (is_sorted(head) == TRUE)
		return ;
	if (size == 5)
		sorting_algo_5n(head);
}

void	call_sorting_algo(t_struct *head)
{
	t_sort		*sort;
	t_struct	tmp;

	tmp = *head;
	sort = init_stack_var(head);
	sort = init_stack_chunks(head, sort);
	if (is_sorted(head) == TRUE)
		return ;
	prepare_push_to_b(head, sort, tmp);
	sort->j = sort->total - 1;
	sorting_part(head, sort, tmp);
}
