/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:49:52 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:49:53 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_struct *head)
{
	push_a_or_b(&(head->l_b), &(head->l_a));
	ft_putstr("pa\n");
}

void	push_b(t_struct *head)
{
	push_a_or_b(&(head->l_a), &(head->l_b));
	ft_putstr("pb\n");
}
