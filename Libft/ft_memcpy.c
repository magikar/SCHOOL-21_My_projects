/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:58:00 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/18 13:27:55 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict srt, size_t n)
{
	unsigned int	i;
	unsigned char	*mem_dest;
	unsigned char	*mem_srt;

	i = 0;
	mem_dest = (unsigned char*)dest;
	mem_srt = (unsigned char*)srt;
	if (!mem_dest && !mem_srt)
		return (NULL);
	while (i < n)
	{
		*(mem_dest++) = *(mem_srt++);
		i++;
	}
	return (dest);
}
