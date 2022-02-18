/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:23:09 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/18 15:31:18 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		my_count_str(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (*s)
	{
		if (*s == c)
			n = 1;
		if (*s != c && n == 1)
		{
			n = 0;
			i++;
		}
		s++;
	}
	return (i);
}

static int		my_count114(char const *s, int start, char c)
{
	unsigned int	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

static char		**ft_splitfree(char **str)
{
	while (*str)
		free(*str++);
	free(str);
	return (NULL);
}

static char		**heart_split(char **str, char const *s, char c, int count)
{
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (count > 0)
	{
		while (s[start] == c && s[start])
			start++;
		str[i] = ft_substr(s, start, my_count114(s, start, c));
		if (!(str[i]))
			return (ft_splitfree(str));
		i++;
		start += my_count114(s, start, c);
		count--;
	}
	str[i] = NULL;
	return (str);
}

char			**ft_split(char const *s, char c)
{
	int		count;
	char	**str;

	if (!(s))
		return (NULL);
	count = my_count_str(s, c);
	str = (char**)malloc(sizeof(*str) * (count + 1));
	if (!str)
		return (NULL);
	str = heart_split(str, s, c, count);
	return (str);
}
