/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:09:57 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/16 20:07:59 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *srt;

	srt = NULL;
	while (*s)
	{
		if (*s == c)
			srt = (char*)s;
		s++;
	}
	if (srt)
		return (srt);
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}
