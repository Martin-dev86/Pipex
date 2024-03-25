/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:27:52 by cagarci2          #+#    #+#             */
/*   Updated: 2024/03/25 13:42:42 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	init(t_pipex *pipex, int argc, **argv)
{
	if (argc !=5)
		ft_error("Error en número de argumentos");
	pipex->fd_in
	if ()
	{
		
	}
	
	
}
int main(int argc, char **argc, pid_t pid)
{
	pid_t pid;
	int	fd_in[2];
	int	fd_out;

	pipe(fd_in);

	pid = fork()
	if (pid == 0)
	{
		close(READ_END);
		dup2(fd_in[WRITE_END], STDOUT_FILENO);
		close(fd_in[WRITE_END])
	}
	else
	{
		
	}
	else (pid < 0)
		

}