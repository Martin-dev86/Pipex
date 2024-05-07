/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:27:52 by cagarci2          #+#    #+#             */
/*   Updated: 2024/04/11 14:06:21 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(char *error)
{
	perror(error);
}

void	error_path(char *str)
{
	perror(str);
	if (ft_strncmp(str, "Infile", 6) == 0)
		exit(0);
	exit(EXIT_FAILURE);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	init(t_pipex *pipex, int argc, char **argv)
{
	if (argc != 5)
		ft_error("Error");
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in < 0)
		ft_error("Error en archivo de entrada");
	pipex->fd_out = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->fd_out < 0)
		ft_error("Error en archivo de entrada");
	if (pipe(pipex->fd_pipe) < 0)
		ft_error("pipe");
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	init(&pipex, argc, argv);
	pipex.path = found_path(env);
	if (!pipex.path)
		error_path("PATH");
	pipex.array_path = ft_split(pipex.path, ':');
	if (!pipex.array_path)
		ft_error("Error");
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		ft_error("Error pid1");
	if (pipex.pid1 == 0)
		process_child1(pipex, argv, env);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		ft_error("Error pid2");
	if (pipex.pid2 == 0)
		process_child2(pipex, argv, argc, env);
	process_dad(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}
