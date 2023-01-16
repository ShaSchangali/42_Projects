/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:12:02 by sschanga          #+#    #+#             */
/*   Updated: 2022/08/29 00:30:47 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_node	*root = NULL;
	t_node			*curr;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	curr = check_fd_line(root, fd);
	if (curr == NULL)
		return (NULL);
	if (root == NULL)
		root = curr;
	curr->content = read_and_store(fd, curr->content);
	if (curr->content == NULL || *(curr->content) == '\0')
	{
		root = clean_node(root, fd);
		return (NULL);
	}
	line = create_newline(curr->content);
	if (line == NULL)
	{
		root = clean_node(root, fd);
		return (NULL);
	}
	curr->content = cpy_newline(curr->content);
	return (line);
}

t_node	*check_fd_line(t_node *root, int fd)
{
	t_node	*curr;
	t_node	*cpy_curr;

	if (root == NULL)
	{
		root = get_last_node(fd);
		if (root == NULL)
			return (NULL);
	}
	curr = root;
	while (curr->next != NULL)
	{
		if (curr->fd == fd)
			return (curr);
		curr = curr->next;
	}
	if (curr->fd != fd)
	{
		cpy_curr = get_last_node(fd);
		if (cpy_curr == NULL)
			return (NULL);
		curr->next = cpy_curr;
		return (cpy_curr);
	}
	return (curr);
}

char	*create_newline(char *root)
{
	char	*curr;
	int		len;

	len = check_newline(root);
	if (len < 0)
	{
		curr = (char *)malloc(sizeof(char) * (ft_strlen(root) + 1));
		if (curr == NULL)
		{
			free(root);
			return (NULL);
		}
		ft_strlcpy(curr, root, ft_strlen(root) + 1);
		return (curr);
	}
	curr = (char *)malloc(sizeof(char) * (len + 2));
	if (curr == NULL)
	{
		free(root);
		return (NULL);
	}
	ft_strlcpy(curr, root, len + 2);
	return (curr);
}

char	*read_and_store(int fd, char *root)
{
	t_read	store;

	store.buff[BUFFER_SIZE] = '\0';
	store.nbyte_read = read(fd, store.buff, BUFFER_SIZE);
	if (root == NULL || store.nbyte_read <= 0)
	{
		if (root == NULL || root[0] != '\0')
			return (root);
		free(root);
		return (NULL);
	}
	while (store.nbyte_read > 0)
	{
		store.curr = (char *)malloc(ft_strlen(root) + store.nbyte_read + 1);
		store.curr[0] = '\0';
		ft_strlcpy(store.curr, root, ft_strlen(root) + 1);
		ft_strlcpy(&store.curr[ft_strlen(root)], store.buff, \
			store.nbyte_read + 1);
		free(root);
		if (check_newline(store.curr) != -1)
			break ;
		root = store.curr;
		store.nbyte_read = read(fd, &store.buff, BUFFER_SIZE);
	}
	return (store.curr);
}

char	*cpy_newline(char *root)
{
	char	*cpy_node;
	int		len;
	size_t	add_newlen;

	if (check_newline(root) == -1)
	{
		free(root);
		return (NULL);
	}
	len = check_newline(root);
	add_newlen = ft_strlen(root) - len;
	cpy_node = (char *)malloc(sizeof(char) * add_newlen);
	if (cpy_node == NULL)
	{
		free(root);
		return (NULL);
	}
	ft_strlcpy(cpy_node, &root[len + 1], add_newlen);
	free(root);
	return (cpy_node);
}
