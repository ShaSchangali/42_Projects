/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschanga <sschanga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:07:33 by sschanga          #+#    #+#             */
/*   Updated: 2022/12/01 20:26:04 by sschanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*set_argv(char **path, char *cmd)
{
	char	*add_slash;
	char	*add_argv;
	t_path	pipex;

	while (*path != NULL)
	{
		add_slash = ft_strjoin(*path, "/");
		if (!add_slash)
			perror_msg(&pipex);
		add_argv = ft_strjoin(add_slash, cmd);
		free(add_slash);
		if (!add_argv)
			perror_msg(&pipex);
		if (access(add_argv, F_OK) == 0)
		{
			cmd = ft_strdup(add_argv);
			free(add_argv);
			free(cmd);
			return (cmd);
		}
		free(add_argv);
		path++;
	}
	return (NULL);
}

void	set_null(t_path *pipex)
{
	int	i;

	i = 0;
	while (i++ < 2)
	{
		pipex->cmds[i].cmd = NULL;
		pipex->cmd_path[i].cmd_argv = NULL;
	}
	pipex->path = NULL;
	pipex->infile = NULL;
	pipex->outfile = NULL;
}

void	argv_child(t_path *pipex, char **argv, char **envp)
{
	dup2(pipex->fd[1], STDOUT_FILENO);
	close(pipex->fd[0]);
	pipex->infile_fd = open(pipex->infile, O_RDONLY, 0777);
	if (pipex->infile_fd == -1)
		perror_msg(pipex);
	dup2(pipex->infile_fd, STDIN_FILENO);
	close(pipex->fd[1]);
	close(pipex->infile_fd);
	pipex->cmd_path[0].cmd_argv = set_argv(pipex->path, *pipex->cmds[0].cmd);
	execve(pipex->cmd_path[0].cmd_argv, pipex->cmds[0].cmd, envp);
	perror_msg(pipex);
}

void	argv_parent(t_path *pipex, char **argv, char **envp)
{
	dup2(pipex->fd[0], STDIN_FILENO);
	close(pipex->fd[1]);
	pipex->outfile_fd
		= open(pipex->outfile, O_TRUNC | O_CREAT | O_WRONLY, 0664);
	dup2(pipex->outfile_fd, STDOUT_FILENO);
	if (pipex->outfile_fd == -1)
		perror_msg(pipex);
	close(pipex->fd[0]);
	close(pipex->outfile_fd);
	pipex->cmd_path[1].cmd_argv = set_argv(pipex->path, *pipex->cmds[1].cmd);
	execve(pipex->cmd_path[1].cmd_argv, pipex->cmds[1].cmd, envp);
	perror_msg(pipex);
}
