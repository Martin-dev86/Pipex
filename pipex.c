/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:27:52 by cagarci2          #+#    #+#             */
/*   Updated: 2024/03/27 11:47:07 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_pipex *pipex, int argc, char **argv)
{
	if (argc != 5)
		ft_error("Error en número de argumentos");
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in < 0)
		ft_error("Error en archivo de entrada");
	pipex->fd_out = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex->fd_out < 0)
		ft_error("Error en archivo de entrada");
	if (pipe(pipex->fd_pipe) < 0)
		ft_error("Erro en la tubería");
}
int main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		ft_error("Error al crear 1º hijo.");
	if (pipex.pid1 == 0)
	{
		close(READ_END);
		dup2(pipex.fd_pipe[0][WRITE_END], STDOUT_FILENO);
		close(pipex.fd_pipe[0][WRITE_END])
	}
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		ft_error("Error al crear 2º hijo.");
	if (pipex.pid2 == 0)
	{
		close(WRITE_END);
		dup2(pipex.fd_pipe[1][READ_END], STDIN_FILENO);
		close(pipex.fd_pipe[1]);
	}
}