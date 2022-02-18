/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:42:16 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/18 14:08:04 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*my_obrezka(char const *set, char *ret)
{
	int		j;
	int		k;
	char	*r;

	r = ret;
	k = 0;
	while (ret[k])
		k++;
	while (k-- > 0)
	{
		j = 0;
		while (set[j])
		{
			if (ret[k] == set[j])
			{
				ret[k] = '\0';
				break ;
			}
			j++;
		}
		if (!(set[j]))
			break ;
	}
	return (r);
}

static char	*my_cpy(char const *s1, char const *set, char *ret)
{
	int		j;
	char	*r;

	r = ret;
	while (*s1)
	{
		j = 0;
		while (set[j])
		{
			if (*s1 == set[j])
				break ;
			j++;
		}
		if (!(set[j]))
		{
			while (*s1)
				*(ret++) = *(s1++);
			*ret = '\0';
			break ;
		}
		s1++;
	}
	return (r);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*ret;
	char	*ret2;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	ret = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!(ret))
		return (NULL);
	ret = my_cpy(s1, set, ret);
	ret = my_obrezka(set, ret);
	ret2 = (char*)malloc(sizeof(char) * (ft_strlen(ret) + 1));
	if (!(ret2))
		return (NULL);
	ft_memcpy(ret2, ret, ft_strlen(ret) + 1);
	free(ret);
	return (ret2);
}
