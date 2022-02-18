/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:02:54 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/20 18:11:55 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			separation_x(t_specifier *spec, t_flags *flag, va_list *arg)
{
	int i;

	i = 0;
	if (flag->longg)
	{
		spec->ld = va_arg(*arg, long int);
		i = print_x_long(spec->ld, flag);
	}
	else if (flag->shortt)
	{
		spec->hd = va_arg(*arg, int);
		i = print_x_short(spec->hd, flag);
	}
	else
	{
		spec->d = va_arg(*arg, int);
		i = print_x(spec->d, flag);
	}
	return (i);
}

int			separation_bigx(t_specifier *spec, t_flags *flag, va_list *arg)
{
	int i;

	i = 0;
	if (flag->longg)
	{
		spec->ld = va_arg(*arg, long int);
		i = print_bigx_long(spec->ld, flag);
	}
	else if (flag->shortt)
	{
		spec->hd = va_arg(*arg, int);
		i = print_bigx_short(spec->hd, flag);
	}
	else
	{
		spec->d = va_arg(*arg, int);
		i = print_bigx(spec->d, flag);
	}
	return (i);
}

static int	print_minus_x(unsigned int x, char *dec_16,
		int n, t_flags *flag)
{
	if (flag->sharp && x != 0)
	{
		ft_putstr("0x");
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

static int	print_no_minus_x(unsigned int x, int n, t_flags *flag)
{
	int i;

	i = n;
	if (flag->sharp && x != 0)
		i += 2;
	while ((!flag->zero && i < flag->width && !flag->dot) || (i < flag->width
				&& flag->accuracy < flag->width && flag->dot))
	{
		ft_putchar(' ');
		n++;
		flag->width--;
	}
	if (flag->sharp && x != 0)
	{
		ft_putstr("0x");
		n += 2;
	}
	n = no_minus_print_help(n, i + 2, flag);
	return (n);
}

int			print_x(int x, t_flags *flag)
{
	int		i;
	int		n;
	char	*dec_16;

	if (x == 0 && flag->accuracy == 0 && flag->dot)
	{
		n = flag->width;
		ft_putnchar(' ', n);
		return (n);
	}
	dec_16 = ft_itoa_base(x, 16);
	i = ft_strlen(dec_16);
	n = i;
	if (flag->sharp && x != 0)
		flag->accuracy += 2;
	if (flag->minus)
		n = print_minus_x(x, dec_16, n, flag);
	else
	{
		n = print_no_minus_x(x, n, flag);
		ft_putstr(dec_16);
	}
	free(dec_16);
	return (n);
}
