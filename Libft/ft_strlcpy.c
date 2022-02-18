/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:50:10 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/16 20:09:12 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dest, const char *restrict src, size_t size)
{
	unsigned int	i;
	const char		*cpy_src;

	i = 0;
	if (src == NULL)
		return (0);
	cpy_src = src;
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = cpy_src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
