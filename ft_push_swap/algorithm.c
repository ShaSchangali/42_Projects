/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:48:52 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:48:55 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_struct *type, char *str)
{
	if (ft_get_nb_strs(str, ' ') == 2)
		call_algo_2n(type, type->max_size);
	else if (ft_get_nb_strs(str, ' ') == 3)
		call_algo_3n(type, 3);
	else if (ft_get_nb_strs(str, ' ') == 4)
		call_algo_4n(type, type->max_size);
	else if (ft_get_nb_strs(str, ' ') == 5)
		call_algo_5n(type, type->max_size);
	else if (ft_get_nb_strs(str, ' ') >= 6)
		call_sorting_algo(type);
}
