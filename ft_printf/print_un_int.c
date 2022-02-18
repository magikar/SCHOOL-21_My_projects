/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_un_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 15:04:40 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/19 19:36:53 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			separation_int(t_specifier *spec, t_flags *flag, va_list *arg)
{
	int i;

	i = 0;
	if (flag->longg)
	{
		spec->ld = va_arg(*arg, long int);
		i = print_int_long(spec->ld, flag);
	}
	else if (flag->shortt)
	{
		spec->hd = va_arg(*arg, int);
		i = print_int_short(spec->hd, flag);
	}
	else
	{
		spec->d = va_arg(*arg, int);
		i = print_int(spec->d, flag);
	}
	return (i);
}

int			separation_int_un(t_specifier *spec, t_flags *flag, va_list *arg)
{
	int i;

	i = 0;
	if (flag->longg)
	{
		spec->ld = va_arg(*arg, long int);
		i = print_un_int_long(spec->ld, flag);
	}
	else if (flag->shortt)
	{
		spec->hd = va_arg(*arg, int);
		i = print_un_int_short(spec->hd, flag);
	}
	else
	{
		spec->d = va_arg(*arg, int);
		i = print_un_int(spec->d, flag);
	}
	return (i);
}

static int	print_minus_u(unsigned int u, int i, t_flags *flag)
{
	while (i < flag->accuracy)
	{
		ft_putchar('0');
		i++;
	}
	ft_putnbr_un(u);
	while (i < flag->width)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

static int	print_no_minus_u(unsigned int u, int n, t_flags *flag)
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
	ft_putnbr_un(u);
	return (n);
}

int			print_un_int(int u, t_flags *flag)
{
	int	i;

	if (u == 0 && flag->accuracy == 0 && flag->dot)
	{
		i = flag->width;
		ft_putnchar(' ', i);
		return (i);
	}
	i = amount_numbers_un((unsigned int)u);
	if (flag->minus)
		i = print_minus_u(u, i, flag);
	else
		i = print_no_minus_u(u, i, flag);
	return (i);
}
