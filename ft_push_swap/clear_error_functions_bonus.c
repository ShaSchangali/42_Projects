/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_error_functions_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:49:25 by sschanga          #+#    #+#             */
/*   Updated: 2023/01/15 22:03:51 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_free_node(t_list **node)
{
	t_list	*tmp;
	t_list	*head;

	head = *node;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	*node = NULL;
}

void	free_everything(t_struct *type)
{
	ft_free_node(&type->l_a);
	ft_free_node(&type->l_b);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	error(t_struct *type, int n)
{
	write(2, "Error\n", 6);
	if (n == 1)
		free_everything(type);
	exit(EXIT_FAILURE);
}

void	deletestr(char	**a)
{
	int		j;

	j = 0;
	if (!a)
		return ;
	while (a[j])
	{
		free (a[j]);
		j++;
	}
	free(a);
	a = NULL;
}
