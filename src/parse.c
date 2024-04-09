/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:31:43 by cagarci2          #+#    #+#             */
/*   Updated: 2024/03/28 11:31:43 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	count_command(char *str, t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->num_word = 0;
	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;
		while (str[i] != ' ' && str[i])
			i++;
		pipex->num_word++;
		if (str[i] == '\0')
			return (pipex->num_word);
		i++;
	}
	if (pipex->num_word == 0)
		ft_error("ERROR");
	return (pipex->num_word);
}

int	count_char_cmd(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i])
	{
		if (str[i] != '"' && str[i] != ' ' && str[i] != 39)
		{
			i++;
			len++;
		}
		else
			return (len);
	}
	return (len);
}

void	parse_simbols(char *str, t_pipex *pipex)
{
	int	j;

	j = 0;
	pipex->array_argv[pipex->num_cmd] = malloc(sizeof(char *)
			* count_char_cmd(str, pipex->i) + 1);
	if (!pipex->array_argv[pipex->num_cmd])
	{
		ft_free(pipex->array_argv);
		ft_error("Error en el parseo");
	}
	while (str[pipex->i] && (str[pipex->i] != '"'
			&& str[pipex->i] != ' ' && str[pipex->i] != 39))
		pipex->array_argv[pipex->num_cmd][j++] = str[pipex->i++];
	pipex->array_argv[pipex->num_cmd][j] = '\0';
}

char	**parse_argv(char *str, t_pipex *pipex)
{
	pipex->i = 0;
	pipex->num_cmd = 0;
	while (str[pipex->i] && (pipex->num_cmd < pipex->num_word))
	{
		if (str[pipex->i] != ' ')
		{
			if (str[pipex->i] != '"' && str[pipex->i] != 39)
			{
				parse_simbols(str, pipex);
				pipex->num_cmd++;
			}
		}
		pipex->i++;
	}
	return (pipex->array_argv);
}

char	**parsing(char *str)
{
	t_pipex	pipex;

	if (str == NULL)
		return (NULL);
	pipex.num_word = count_command(str, &pipex);
	pipex.array_argv = malloc(sizeof (char *) * (pipex.num_word + 1));
	if (!pipex.array_argv)
		return (NULL);
	pipex.array_argv = parse_argv(str, &pipex);
	pipex.array_argv[pipex.num_word] = NULL;
	return (pipex.array_argv);
}
