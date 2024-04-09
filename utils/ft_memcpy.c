/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagarci2 <cagarci2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:17:23 by cagarci2          #+#    #+#             */
/*   Updated: 2024/04/02 13:49:18 by cagarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dst;
	if ((unsigned char *)dst == 0 && (unsigned char *)src == 0)
		return (0);
	while (n > 0)
	{
		*p_dst = *p_src;
		p_dst++;
		p_src++;
		n--;
	}
	return (dst);
}
