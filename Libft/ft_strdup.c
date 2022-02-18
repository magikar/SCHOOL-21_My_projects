/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:13:34 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/16 20:06:15 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = NULL;
	dest = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(dest))
		return (NULL);
	while (s[i])
	{
		dest[i] = ((char*)s)[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
