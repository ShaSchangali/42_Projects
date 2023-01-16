/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:32:02 by sschanga          #+#    #+#             */
/*   Updated: 2022/08/29 00:33:10 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node	*get_last_node(int fd)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = fd;
	new_node->content = (char *)malloc(sizeof(char));
	new_node->content[0] = '\0';
	new_node->next = NULL;
	return (new_node);
}

int	check_newline(char *root)
{
	int	i;

	i = 0;
	if (root == NULL)
		return (0);
	while (root[i])
	{
		if (root[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

t_node	*clean_node(t_node *root, int fd)
{
	t_node	*new_node;
	t_node	*curr;

	curr = root;
	new_node = curr->next;
	if (curr->fd == fd)
	{
		free(curr->content);
		free(curr);
		return (new_node);
	}
	while (new_node != NULL)
	{
		if (new_node->fd == fd)
		{
			curr->next = new_node->next;
			if (new_node->content != NULL)
				free(new_node->content);
			free(new_node);
			return (root);
		}
		curr = curr->next;
		new_node = curr->next;
	}
	return (root);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	i = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}
