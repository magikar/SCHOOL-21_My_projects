/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:08:22 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/11 18:17:43 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*mem_s;

	i = 0;
	mem_s = (unsigned char*)s;
	while (++i <= n)
	{
		if (*(mem_s++) == (unsigned char)c)
			return ((void*)--mem_s);
	}
	return (0);
}
