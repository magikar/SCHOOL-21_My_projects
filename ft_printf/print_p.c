/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 19:47:18 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/13 20:58:33 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_adress(void *adr)
{
	char	*buf;
	int		i;
	size_t	p;
	size_t	dig;

	p = (size_t)adr;
	i = amount_numbers_dec16(p);
	buf = (char*)malloc(i + 3);
	i += 2;
	buf[i--] = '\0';
	buf[0] = '0';
	buf[1] = 'x';
	if (p == 0)
		buf[i] = '0';
	while (p)
	{
		dig = ((size_t)p) % 16;
		if (dig < 10)
			buf[i] = '0' + dig;
		else
			buf[i] = 'a' + (dig - 10);
		p /= 16;
		i--;
	}
	return (buf);
}

static int	print_minus_p(char *pointer, int i, t_flags *flag)
{
	if ((i - 2) < flag->accuracy)
	{
		ft_putstr("0x0");
		pointer += 2;
		i++;
	}
	while ((i - 2) < flag->accuracy)
	{
		ft_putchar('0');
		i++;
	}
	ft_putstr(pointer);
	while (i < flag->width)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

static int	print_no_minus_p(char *pointer, int i, t_flags *flag)
{
	int n;

	n = i;
	while ((!flag->zero && n < flag->width && !flag->dot) ||
		(n < flag->width && (flag->width - 2 > flag->accuracy) && flag->dot))
	{
		ft_putchar(' ');
		i++;
		flag->width--;
	}
	if ((n - 2 < flag->accuracy) || (flag->zero && i < flag->width &&
		!flag->dot))
	{
		ft_putstr("0x0");
		pointer += 2;
		i++;
		flag->accuracy--;
	}
	i = no_minus_print_help(i, n, flag);
	ft_putstr(pointer);
	return (i);
}

int			print_p(void *p, t_flags *flag)
{
	int		i;
	char	*pointer;

	if ((char*)p == NULL && flag->accuracy == 0 && flag->dot)
		pointer = "0x";
	else if ((char*)p == NULL && flag->accuracy > 0)
		pointer = "0x0";
	else
		pointer = ft_adress(p);
	i = ft_strlen(pointer);
	if (flag->minus)
		i = print_minus_p(pointer, i, flag);
	else
		i = print_no_minus_p(pointer, i, flag);
	if (p != NULL)
		free(pointer);
	return (i);
}
