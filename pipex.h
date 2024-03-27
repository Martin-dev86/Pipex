/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:45:17 by cagarci2          #+#    #+#             */
/*   Updated: 2024/03/27 11:50:10 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ_END 0 /* index extremo lectura */
# define WRITE_END 0 /* index extremo escritura */
# define FILE_NAME "file.txt" /* nombre del archivo donde escribir */
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <sys/types.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd_in;
	int		fd_out;
	int		fd_pipe[2];
	char	**array_path;
	char	**array_command;
}	t_pipex;

void	init(t_pipex *pipex, int argc, char **argv);
void	ft_error(char *error);
void	ft_free(char **str);
char	**ft_split(const char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif