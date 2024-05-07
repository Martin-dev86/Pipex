/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:47:39 by cagarci2          #+#    #+#             */
/*   Updated: 2024/03/28 10:47:39 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*found_path(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL && env[i][0] != '\0')
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*cmd_found(char **array_path, char **cmd)
{
	int		i;
	char	*command;

	i = 0;
	while (array_path[i])
	{
		command = ft_strjoin(ft_strjoin(array_path[i], "/"), *cmd);
		if (access(command, X_OK) == 0)
			break ;
		free(command);
		i++;
	}
	return (command);
}

void	process_child1(t_pipex pipex, char **argv, char **env)
{
	pipex.array_command = parsing(argv[2]);
	if (!pipex.array_command)
		ft_error("Error");
	pipex.cmd = cmd_found(pipex.array_path, &pipex.array_command[0]);
	if (!pipex.cmd)
	{
		ft_error("cmd_child");
		ft_free(&pipex.cmd);
		ft_free(pipex.array_command);
	}
	close(pipex.fd_pipe[READ_END]);
	dup2(pipex.fd_pipe[WRITE_END], STDOUT_FILENO);
	close(pipex.fd_pipe[WRITE_END]);
	dup2(pipex.fd_in, STDIN_FILENO);
	close(pipex.fd_in);
	if (execve(pipex.cmd, pipex.array_command, env) == -1)
		ft_error("execve_child");
	exit(0);
}

void	process_child2(t_pipex pipex, char **argv, int argc, char **env)
{
	pipex.array_command = parsing(argv[argc - 2]);
	if (!pipex.array_command)
		ft_error("Error");
	pipex.cmd = cmd_found(pipex.array_path, &pipex.array_command[0]);
	if (!pipex.cmd)
	{
		ft_error("cmd_dad");
		ft_free(&pipex.cmd);
		ft_free(pipex.array_command);
	}
	close(pipex.fd_pipe[WRITE_END]);
	dup2(pipex.fd_pipe[READ_END], STDIN_FILENO);
	close(pipex.fd_pipe[READ_END]);
	dup2(pipex.fd_out, STDOUT_FILENO);
	close(pipex.fd_out);
	if (execve(pipex.cmd, pipex.array_command, env) == -1)
		ft_error("execve_dad");
	exit(0);
}

void	process_dad(t_pipex *pipex)
{
	ft_free(pipex->array_path);
	close(pipex->fd_in);
	close(pipex->fd_out);
	close(pipex->fd_pipe[0]);
	close(pipex->fd_pipe[1]);
}
