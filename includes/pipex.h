/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:45:17 by cagarci2          #+#    #+#             */
/*   Updated: 2024/04/08 13:26:41 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ_END 0 /* index extremo lectura */
# define WRITE_END 1 /* index extremo escritura */
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
	int		i;
	int		fd_in;
	int		fd_out;
	int		num_cmd;
	int		num_word;
	int		fd_pipe[2];
	char	*path;
	char	*cmd;
	char	**array_path;
	char	**array_command;
	char	**array_argv;
}	t_pipex;

void	init(t_pipex *pipex, int argc, char **argv);
void	ft_error(char *error);
void	ft_free(char **str);
char	*found_path(char **env);
char	*cmd_found(char **array_path, char **cmd);
char	**parse_argv(char *str, t_pipex *pipex);
int		count_command(char	*str, t_pipex *pipex);
int		count_char_cmd(char *str, int i);
void	parse_simbols(char *str, t_pipex *pipex);
char	**parsing(char *str);
void	process_child2(t_pipex pipex, char **argv, int argc, char **env);
void	process_child1(t_pipex pipex, char **argv, char **env);
void	process_dad(t_pipex *pipex);
char	**ft_split(const char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *c);
char	*ft_strjoin(char const *s1, char const *s2);
#endif