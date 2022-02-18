/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:27:47 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/11 22:39:04 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *str;

	str = malloc(nmemb * size);
	if (str == 0)
		return (NULL);
	ft_bzero(str, size * nmemb);
	return (str);
}
