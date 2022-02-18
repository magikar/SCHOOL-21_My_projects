/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:26:07 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/24 22:41:51 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count111(int n)
{
	unsigned int	cocou;
	unsigned int	a;

	cocou = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		a = (unsigned int)-n;
		cocou++;
	}
	else
		a = (unsigned int)n;
	while (a > 0)
	{
		a /= 10;
		cocou++;
	}
	return (cocou);
}

static unsigned int	ft_count112(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char				*ft_itoa(int n)
{
	char			*s;
	unsigned int	len;
	int				a;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	a = n;
	len = ft_count111(n);
	s = (char*)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	len--;
	if (a == 0)
		s[0] = '0';
	if (a < 0)
		a = -n;
	while (a > 0)
	{
		s[len--] = a % 10 + '0';
		a = a / 10;
	}
	if (ft_count112(n) == 1)
		s[0] = '-';
	return (s);
}
