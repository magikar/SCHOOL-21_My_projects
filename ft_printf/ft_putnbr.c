/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 14:31:48 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/20 18:10:22 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	unsigned int i;

	if (n < 0)
	{
		i = -n;
	}
	else
		i = n;
	if (i >= 10)
		ft_putnbr(i / 10);
	ft_putchar((char)(i % 10 + 48));
}

void	ft_putnbr_un(unsigned int n)
{
	unsigned int i;

	i = n;
	if (i >= 10)
		ft_putnbr_un(i / 10);
	ft_putchar((char)(i % 10 + 48));
}

void	ft_putnbr_long(long int n)
{
	unsigned long int i;

	if (n < 0)
	{
		i = -n;
	}
	else
		i = n;
	if (i >= 10)
		ft_putnbr_long(i / 10);
	ft_putchar((char)(i % 10 + 48));
}

void	ft_putnbr_un_long(unsigned long int n)
{
	unsigned long int i;

	i = n;
	if (i >= 10)
		ft_putnbr_un_long(i / 10);
	ft_putchar((char)(i % 10 + 48));
}
