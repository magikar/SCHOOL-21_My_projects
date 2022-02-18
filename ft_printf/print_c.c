/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:55:13 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/11 16:19:54 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c(const int c, t_flags *flag)
{
	int i;

	i = 1;
	if (flag->minus)
		ft_putchar(c);
	if (flag->zero && flag->width > 1 && !flag->minus)
	{
		ft_putnchar('0', flag->width - 1);
		i += flag->width - 1;
	}
	else if (flag->width > 1)
	{
		ft_putnchar(' ', flag->width - 1);
		i += flag->width - 1;
	}
	if (!flag->minus)
		ft_putchar(c);
	return (i);
}
