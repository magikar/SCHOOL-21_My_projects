/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:30:06 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/09 15:05:52 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	void			*v;

	i = 0;
	v = b;
	while (i < len)
	{
		((unsigned char*)b)[i] = c;
		i++;
	}
	return (v);
}
