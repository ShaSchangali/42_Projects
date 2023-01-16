/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:32:43 by sschanga          #+#    #+#             */
/*   Updated: 2022/08/29 00:30:28 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct node
{
	int			fd;
	char		*content;
	struct node	*next;
}	t_node;

typedef struct s_read
{
	char	buff[BUFFER_SIZE + 1];
	char	*curr;
	int		nbyte_read;
}	t_read;

char	*get_next_line(int fd);
t_node	*check_fd_line(t_node *root, int fd);
t_node	*get_last_node(int fd);
int		check_newline(char *root);
char	*create_newline(char *root);
char	*read_and_store(int fd, char *root);
char	*cpy_newline(char *root);
t_node	*clean_node(t_node *root, int fd);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
#endif