/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <tmagikar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:36:03 by tmagikar          #+#    #+#             */
/*   Updated: 2021/04/12 12:42:53 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup("\0"));
	if (len >= ft_strlen(s + start))
		str = (char *)malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	while (i < len && s)
	{
		str[i] = (char)s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
