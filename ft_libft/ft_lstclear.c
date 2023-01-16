/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:44:22 by sschanga          #+#    #+#             */
/*   Updated: 2022/07/17 01:17:13 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*temp;

// 	temp = *lst;
// 	while (temp)
// 	{
// 		ft_lstdelone(temp, del);
// 		temp = temp -> next;
// 	}
// 	*lst = NULL;
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clr;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		clr = *lst;
		*lst = (*lst)->next;
		del(clr->content);
		free(clr);
	}
}
