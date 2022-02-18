/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:37:59 by tmagikar          #+#    #+#             */
/*   Updated: 2020/11/19 17:43:16 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int i;

	i = n;
	if (n < 0)
	{
		i = -n;
		ft_putchar_fd('-', fd);
	}
	if (i >= 10)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd((char)(i % 10 + 48), fd);
}
