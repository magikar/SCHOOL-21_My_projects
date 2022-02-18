/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:19:14 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/18 14:20:18 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*a;

	if (!s1 || !s2)
		return (NULL);
	k = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	a = (char*)malloc(sizeof(char) * (k + 1));
	if (!(a))
		return (NULL);
	i = 0;
	k = 0;
	while (((char*)s1)[i])
		a[k++] = ((char*)s1)[i++];
	i = 0;
	while (((char*)s2)[i])
		a[k++] = ((char*)s2)[i++];
	a[k] = '\0';
	return (a);
}
