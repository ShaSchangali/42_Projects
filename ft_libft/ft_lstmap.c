/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 21:53:27 by sschanga          #+#    #+#             */
/*   Updated: 2022/07/14 02:51:19 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp_list;
	t_list	*orig;
	t_list	*newlist;

	newlist = NULL;
	orig = lst;
	while (orig)
	{
		tmp_list = ft_lstnew(f(orig->content));
		if (tmp_list)
			ft_lstadd_back(&newlist, tmp_list);
		else
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		orig = orig->next;
	}
	return (newlist);
}
