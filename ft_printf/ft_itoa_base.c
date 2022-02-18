/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 16:34:04 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/20 18:08:26 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_cocou(unsigned int d, int base, size_t *tmp)
{
	int		i;
	size_t	t;

	i = 0;
	if (d == 0)
		return (1);
	t = d;
	*tmp = t;
	while (t > 0)
	{
		t /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(int d, int base)
{
	int		flag;
	int		len;
	size_t	tmp;
	char	*str;
	char	set[17];

	flag = 0;
	len = 0;
	ft_memcpy(set, "0123456789abcdef", 17);
	if (d < 0 && base == 10)
		flag = 1;
	len = ft_cocou((unsigned int)d, base, &tmp) + flag;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (d == 0)
		str[0] = '0';
	if (flag)
		str[0] = '-';
	while (tmp > 0 && d != 0)
	{
		str[len--] = set[tmp % base];
		tmp /= base;
	}
	return (str);
}

static int	ft_cocou_l(unsigned long int d, int base, size_t *tmp)
{
	int		i;
	size_t	t;

	i = 0;
	if (d == 0)
		return (1);
	t = d;
	*tmp = t;
	while (t > 0)
	{
		t /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base_l(long int d, int base)
{
	int		flag;
	int		len;
	size_t	tmp;
	char	*str;
	char	set[17];

	flag = 0;
	len = 0;
	ft_memcpy(set, "0123456789abcdef", 17);
	if (d < 0 && base == 10)
		flag = 1;
	len = ft_cocou_l((unsigned long int)d, base, &tmp) + flag;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (d == 0)
		str[0] = '0';
	if (flag)
		str[0] = '-';
	while (tmp > 0 && d != 0)
	{
		str[len--] = set[tmp % base];
		tmp /= base;
	}
	return (str);
}
