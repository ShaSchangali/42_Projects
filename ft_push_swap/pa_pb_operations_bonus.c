/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:49:44 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:49:48 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_a(t_struct *head)
{
	push_a_or_b(&(head->l_b), &(head->l_a));
}

void	push_b(t_struct *head)
{
	push_a_or_b(&(head->l_a), &(head->l_b));
}
