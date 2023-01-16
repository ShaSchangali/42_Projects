/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:51:30 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:51:31 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_struct *head)
{
	reverse_rotate_last_becomes_first(&(head->l_a));
	ft_putstr("rra\n");
}

void	reverse_rotate_b(t_struct *head)
{
	reverse_rotate_last_becomes_first(&(head->l_b));
	ft_putstr("rrb\n");
}

void	reverse_rotate_a_b(t_struct *head)
{
	reverse_rotate_last_becomes_first(&(head->l_b));
	reverse_rotate_last_becomes_first(&(head->l_a));
	ft_putstr("rrr\n");
}
