/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 16:27:46 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/20 18:16:09 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_null(t_flags *flag)
{
	flag->space = 0;
	flag->minus = 0;
	flag->plus = 0;
	flag->zero = 0;
	flag->dot = 0;
	flag->sharp = 0;
	flag->width = 0;
	flag->accuracy = 0;
	flag->longg = 0;
	flag->shortt = 0;
}
