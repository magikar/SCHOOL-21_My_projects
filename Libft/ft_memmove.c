/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:02:20 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/16 13:20:00 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*mem_dest;
	unsigned char	*mem_src;

	i = 1;
	mem_dest = (unsigned char*)dest;
	mem_src = (unsigned char*)src;
	if (mem_dest == NULL && mem_src == NULL)
		return (NULL);
	if (mem_dest > mem_src)
		while (i <= len)
		{
			mem_dest[len - i] = mem_src[len - i];
			i++;
		}
	else
		while (len > 0)
		{
			*mem_dest = *mem_src;
			mem_dest++;
			mem_src++;
			len--;
		}
	return (dest);
}
