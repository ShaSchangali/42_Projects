/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:50:31 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/15 22:27:25 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_struct	*type;
	char		**strs;
	char		*str;

	type = malloc(sizeof(t_struct));
	if (ac == 1)
		free(type);
	if (ac > 1)
	{
		if (check_char(av) == FALSE)
			error(type, 1);
		str = parseme(av, ac);
		check_string(str, type);
		strs = ft_split(str, ' ');
		if (!parsing(type, ft_get_nb_strs(str, ' '), strs))
			error(type, 1);
		ft_init_stacks(type);
		algorithm(type, str);
		free(str);
		deletestr(strs);
		free(type->nbr);
		free_everything(type);
		free(type);
	}
	return (0);
}
