/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:45:17 by cagarci2          #+#    #+#             */
/*   Updated: 2024/03/25 13:59:05 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ_END 0 /* index extremo lectura */
# define WRITE_END 0 /* index extremo escritura */
# define FILE_NAME "file.txt" /* nombre del archivo donde escribir */
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <unistd.h>
typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd_in;
	int		fd_out;
	int		fd_pipe[2];
}	t_pipex;

#endif