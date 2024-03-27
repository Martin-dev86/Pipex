/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:57:32 by cagarci2          #+#    #+#             */
/*   Updated: 2024/03/27 11:31:46 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL && env[i][0] != '\0')
	{
		if (ft_strncmp("PATH=", *env[i], 5))
			return (*env[i] + 5);
		i++;
	}
	return (NULL);
}
char	*path_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_split(str, ':'))
			return (*str);
		i++;
	}
	return (NULL);
}
