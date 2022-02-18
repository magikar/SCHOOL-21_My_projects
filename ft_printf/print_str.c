/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:17:20 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/13 16:54:30 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_str_fl(const char *s, t_flags *flag, int wid, int acc)
{
	int i;

	i = wid - acc;
	if (!flag->minus)
	{
		if (flag->zero)
			ft_putnchar('0', i);
		else
			ft_putnchar(' ', i);
		write(1, s, acc);
	}
	else
	{
		write(1, s, acc);
		ft_putnchar(' ', i);
	}
	return (wid);
}

int			print_str(const char *s, t_flags *flag)
{
	int		acc;
	int		wid;

	acc = 0;
	wid = 0;
	if (s == NULL)
		s = "(null)";
	acc = ft_strlen(s);
	if (flag->dot)
		if (acc >= flag->accuracy)
			acc = flag->accuracy;
	if ((wid = acc) <= flag->width)
		wid = flag->width;
	if ((wid - acc) > 0)
		return (print_str_fl(s, flag, wid, acc));
	else
		write(1, s, acc);
	return (acc);
}
