/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:34:09 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/19 15:46:54 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_sign(const int d, t_flags *flag)
{
	if (flag->plus && d >= 0)
	{
		ft_putchar('+');
		return (1);
	}
	else if (d < 0)
	{
		ft_putchar('-');
		return (1);
	}
	else if (flag->space && d >= 0)
	{
		ft_putchar(' ');
		return (1);
	}
	return (0);
}

static int	print_minus_int(int d, int n, t_flags *flag)
{
	int i;

	i = n;
	n += print_sign(d, flag);
	while (i < flag->accuracy--)
	{
		ft_putchar('0');
		n++;
	}
	ft_putnbr(d);
	while (n < flag->width)
	{
		ft_putchar(' ');
		n++;
	}
	return (n);
}

static int	print_no_minus_int(int d, int n, t_flags *flag)
{
	int i;

	i = n;
	if (d < 0 || flag->plus || flag->space)
		flag->width--;
	while ((!flag->zero && !flag->dot && i < flag->width) ||
			(flag->dot && i < flag->width && flag->width > flag->accuracy))
	{
		ft_putchar(' ');
		n++;
		flag->width--;
	}
	if (print_sign(d, flag))
	{
		n++;
		flag->width++;
	}
	n = no_minus_print_help(n, i + 2, flag);
	return (n);
}

static int	split_print_int(const int d, t_flags *flag)
{
	int n;

	n = 0;
	if (flag->minus && (flag->plus || flag->space || d < 0))
	{
		n += print_sign(d, flag);
		flag->width--;
	}
	while (flag->width > 1)
	{
		ft_putchar(' ');
		flag->width--;
		n++;
	}
	if (!flag->minus && (flag->plus || flag->space || d < 0))
	{
		n += print_sign(d, flag);
		flag->width--;
	}
	else if (flag->width == 1)
	{
		ft_putchar(' ');
		n++;
	}
	return (n);
}

int			print_int(const int d, t_flags *flag)
{
	int n;

	n = 0;
	if (d == 0 && flag->accuracy == 0 && flag->dot)
	{
		n = split_print_int(d, flag);
		return (n);
	}
	n = amount_numbers(d);
	if (flag->minus)
		n = print_minus_int(d, n, flag);
	else
	{
		n = print_no_minus_int(d, n, flag);
		ft_putnbr(d);
	}
	return (n);
}
