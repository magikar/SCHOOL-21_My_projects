/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:30:13 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/20 17:55:06 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		amount_numbers(long long d)
{
	int			i;
	long long	n;

	i = 0;
	if (d == 0)
		return (1);
	if (d < 0)
		n = -d;
	else
		n = d;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		amount_numbers_un(unsigned long long d)
{
	int					i;
	unsigned long long	n;

	i = 0;
	if (d == 0)
		return (1);
	n = d;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		amount_numbers_dec16(size_t d)
{
	int		i;
	size_t	n;

	i = 0;
	if (d == 0)
		return (1);
	n = d;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int		no_minus_print_help(int n, int i, t_flags *flag)
{
	while (i - 2 < flag->accuracy || (flag->zero && n < flag->width
				&& !flag->dot))
	{
		ft_putchar('0');
		n++;
		flag->accuracy--;
	}
	return (n);
}
