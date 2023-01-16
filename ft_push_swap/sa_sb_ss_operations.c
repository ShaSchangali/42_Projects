/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:51:42 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:51:43 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_struct *head)
{
	swap_a_or_b(&(head->l_a));
	ft_putstr("sa\n");
}

void	swap_b(t_struct *head)
{
	swap_a_or_b(&(head->l_b));
	ft_putstr("sb\n");
}

void	swap_a_b(t_struct *head)
{
	swap_a_or_b(&(head->l_a));
	swap_a_or_b(&(head->l_b));
	ft_putstr("ss\n");
}
