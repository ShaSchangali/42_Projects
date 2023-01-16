/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_operations_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:51:23 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:51:24 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	reverse_rotate_a(t_struct *head)
{
	reverse_rotate_last_becomes_first(&(head->l_a));
}

void	reverse_rotate_b(t_struct *head)
{
	reverse_rotate_last_becomes_first(&(head->l_b));
}

void	reverse_rotate_a_b(t_struct *head)
{
	reverse_rotate_last_becomes_first(&(head->l_b));
	reverse_rotate_last_becomes_first(&(head->l_a));
}
