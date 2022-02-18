/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:08:10 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/11 14:29:25 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dest,
		const void *restrict src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*mem_dest;
	unsigned char	*mem_src;

	i = 0;
	mem_dest = (unsigned char*)dest;
	mem_src = (unsigned char*)src;
	while (i < n)
	{
		mem_dest[i] = mem_src[i];
		if (mem_dest[i] == (unsigned char)c)
			return ((void*)(dest + i + 1));
		i++;
	}
	return (NULL);
}
