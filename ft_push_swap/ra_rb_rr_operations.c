/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:51:18 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:51:19 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_struct *head)
{
	rotate_top_becomes_last(&(head->l_a));
	ft_putstr("ra\n");
}

void	rotate_b(t_struct *head)
{
	rotate_top_becomes_last(&(head->l_b));
	ft_putstr("rb\n");
}

void	rotate_a_b(t_struct *head)
{
	rotate_top_becomes_last(&(head->l_a));
	rotate_top_becomes_last(&(head->l_b));
	ft_putstr("rr\n");
}
