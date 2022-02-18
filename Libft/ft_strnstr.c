/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:43:34 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/09 19:16:54 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t n)
{
	unsigned int	i;
	unsigned int	count;
	int				j;

	i = 0;
	if (lit[0] == '\0')
		return ((char*)&big[0]);
	while (big[i])
	{
		count = i;
		j = 0;
		while (big[count] == lit[j] && count < n && lit[j])
		{
			count++;
			j++;
		}
		if (lit[j] == '\0')
			return ((char*)&big[i]);
		i++;
	}
	return (NULL);
}
