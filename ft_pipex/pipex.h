/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:25:24 by sschanga          #+#    #+#             */
/*   Updated: 2022/12/01 20:24:36 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_cmd
{
	char	**cmd;
	char	*cmd_argv;
}	t_cmd;

typedef struct s_path
{
	int		fd[2];
	t_cmd	cmds[2];
	t_cmd	cmd_path[2];
	char	**path;
	char	*infile;
	char	*outfile;
	int		infile_fd;
	int		outfile_fd;
}	t_path;

//Pipex
static char	*find_path(char **path);
void		parse_argv(t_path *pipex, char **argv, char **envp);
static char	*set_argv(char **path, char *cmd);
void		set_pipe(t_path *pipex, char **argv, char **envp);
void		argv_child(t_path *pipex, char **argv, char **envp);
void		argv_parent(t_path *pipex, char **argv, char **envp);
//Protect
void		set_null(t_path *pipex);
void		perror_msg(t_path *pipex);
//Libft
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
#endif
