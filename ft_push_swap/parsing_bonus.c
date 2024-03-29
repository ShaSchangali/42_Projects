/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:49:58 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/14 01:50:00 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	get_index(int num, t_list *node)
{
	int	index;

	index = 0;
	while (node)
	{
		if (num > node->num)
		{
			index++;
		}
		node = node->next;
	}
	return (index);
}

t_list	*ft_create_stack(int *indexarr, int count)
{
	int			i;
	t_list		*new_node;
	t_list		*curr;

	i = -1;
	new_node = malloc(sizeof(t_list));
	curr = new_node;
	while (++i < count)
	{
		if (i < count - 1)
			new_node->next = malloc(sizeof(t_list));
		new_node->num = indexarr[i];
		new_node->i = 0;
		if (i == (count - 1))
			new_node->next = NULL;
		else
			new_node = new_node->next;
	}
	new_node = curr;
	while (new_node)
	{
		new_node->i = get_index(new_node->num, curr);
		new_node = new_node->next;
	}
	return (curr);
}

void	ft_init_stacks(t_struct *stacks)
{
	stacks->l_a = ft_create_stack(stacks->nbr, stacks->max_size);
	stacks->l_b = NULL;
}

void	check_doubles(char **av, int ac, t_struct *head)
{
	int			i;
	int			j;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if ((ft_strcmp(av[i], av[j]) == 0)
				|| (mod_atoi(av[i], head) == mod_atoi(av[j], head)))
				error(head, 1);
			j++;
		}
		i++;
	}
}

int	parsing(t_struct *data, int ac, char **av)
{
	int		i;
	int		j;
	int		*tmp;

	i = 0;
	j = 0;
	check_doubles(av, ac, data);
	tmp = malloc((sizeof(int) * ac));
	while (i < ac)
	{
		if (string_has_only_number(av[i]) == FALSE)
			error(data, 1);
		if (!ft_isdigit(av[i][j]) && av[i][j] != '+'
				&& av[i][j] != '-')
			error(data, 1);
		tmp[i] = mod_atoi(av[i], data);
		i++;
	}
	data->max_size = ac;
	data->nbr = tmp;
	return (TRUE);
}
