/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_operations_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:51:36 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:51:37 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_a(t_struct *head)
{
	swap_a_or_b(&(head->l_a));
}

void	swap_b(t_struct *head)
{
	swap_a_or_b(&(head->l_b));
}

void	swap_a_b(t_struct *head)
{
	swap_a_or_b(&(head->l_a));
	swap_a_or_b(&(head->l_b));
}
