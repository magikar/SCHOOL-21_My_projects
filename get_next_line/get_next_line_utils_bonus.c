/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:54:04 by tmagikar          #+#    #+#             */
/*   Updated: 2020/12/16 17:54:26 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(char *s)
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
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	s[0] = '\0';
	return (dest);
}

char		*ft_strchr(const char *s, int c)
{
	int i;

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

char		*ft_strjoin(char const *s1, char const *s2)
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

void		*ft_memmove(void *dest, const void *src, size_t len)
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
