/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:21:40 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/20 18:22:09 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_short(short int n)
{
	unsigned short int i;

	if (n < 0)
		i = -n;
	else
		i = n;
	if (i >= 10)
		ft_putnbr_short(i / 10);
	ft_putchar((char)(i % 10 + 48));
}

void	ft_putnbr_un_short(unsigned short int n)
{
	unsigned short int i;

	i = n;
	if (i >= 10)
		ft_putnbr_un_short(i / 10);
	ft_putchar((char)(i % 10 + 48));
}
