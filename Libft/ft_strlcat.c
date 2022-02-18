/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:20:49 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/11 21:42:20 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dest, const char *restrict src, size_t n)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = ft_strlen(dest);
	k = ft_strlen((char*)src);
	if (n == 0)
		return (k);
	if (j > n)
		return (k + n);
	k += j;
	while (j < n - 1 && src[i])
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (k);
}
