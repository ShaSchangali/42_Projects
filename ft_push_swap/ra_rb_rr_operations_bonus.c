/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_operations_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:51:13 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:51:14 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate_a(t_struct *head)
{
	rotate_top_becomes_last(&(head->l_a));
}

void	rotate_b(t_struct *head)
{
	rotate_top_becomes_last(&(head->l_b));
}

void	rotate_a_b(t_struct *head)
{
	rotate_top_becomes_last(&(head->l_a));
	rotate_top_becomes_last(&(head->l_b));
}
