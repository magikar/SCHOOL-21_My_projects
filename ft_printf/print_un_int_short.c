/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un_int_short.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:03:54 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/20 18:03:59 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_minus_u_short(unsigned short int u, int i, t_flags *flag)
{
	while (i < flag->accuracy)
	{
		ft_putchar('0');
		i++;
	}
	ft_putnbr_un_short(u);
	while (i < flag->width)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

static int	print_no_minus_u_short(unsigned short int u, int n, t_flags *flag)
{
	int i;

	i = n;
	while ((!flag->zero && !flag->dot && i < flag->width) ||
			(flag->dot && i < flag->width && flag->width > flag->accuracy))
	{
		ft_putchar(' ');
		n++;
		flag->width--;
	}
	n = no_minus_print_help(n, i + 2, flag);
	ft_putnbr_un_short(u);
	return (n);
}

int			print_un_int_short(short int u, t_flags *flag)
{
	int	i;

	if (u == 0 && flag->accuracy == 0 && flag->dot)
	{
		i = flag->width;
		ft_putnchar(' ', i);
		return (i);
	}
	i = amount_numbers_un((unsigned short int)u);
	if (flag->minus)
		i = print_minus_u_short(u, i, flag);
	else
		i = print_no_minus_u_short(u, i, flag);
	return (i);
}
