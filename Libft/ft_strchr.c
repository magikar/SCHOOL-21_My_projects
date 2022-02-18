/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:54:06 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/16 20:05:37 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (((char*)s)[i] == c)
			return ((char*)&s[i]);
		i++;
	}
	if (c == 0 && c == s[i])
		return ((char*)&s[i]);
	return (NULL);
}
