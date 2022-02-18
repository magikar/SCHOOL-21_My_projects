/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bigx_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:03:12 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/20 18:22:57 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_minus_bx_long(long int x, char *dec_16,
		int n, t_flags *flag)
{
	if (flag->sharp && x != 0)
	{
		ft_putstr("0X");
		n += 2;
	}
	while (n < flag->accuracy)
	{
		ft_putchar('0');
		n++;
	}
	ft_putstr(dec_16);
	while (n < flag->width)
	{
		ft_putchar(' ');
		n++;
	}
	return (n);
}

static int		print_no_minus_bx_long(long int x, int n, t_flags *flag)
{
	int i;

	i = n;
	if (flag->sharp && x != 0)
		i += 2;
	while ((!flag->zero && i < flag->width && !flag->dot) ||
			(i < flag->width && flag->accuracy < flag->width && flag->dot))
	{
		ft_putchar(' ');
		n++;
		flag->width--;
	}
	if (flag->sharp && x != 0)
	{
		ft_putstr("0X");
		n += 2;
	}
	n = no_minus_print_help(n, i + 2, flag);
	return (n);
}

int				print_bigx_long(long int x, t_flags *flag)
{
	int		n;
	char	*dec_16;

	if (x == 0 && flag->accuracy == 0 && flag->dot)
	{
		n = flag->width;
		ft_putnchar(' ', n);
		return (n);
	}
	dec_16 = ft_itoa_base_l((unsigned long int)x, 16);
	big_x(dec_16);
	n = ft_strlen(dec_16);
	if (flag->sharp && x != 0)
		flag->accuracy += 2;
	if (flag->minus)
		n = print_minus_bx_long(x, dec_16, n, flag);
	else
	{
		n = print_no_minus_bx_long(x, n, flag);
		ft_putstr(dec_16);
	}
	free(dec_16);
	return (n);
}
