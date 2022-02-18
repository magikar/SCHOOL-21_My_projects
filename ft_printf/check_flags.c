/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 15:47:19 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/20 18:02:51 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*check_flags(const char *point_str, t_flags *flag)
{
	while (ft_isflag(*point_str))
	{
		if (*point_str == ' ')
			flag->space = 1;
		else if (*point_str == '-')
			flag->minus = 1;
		else if (*point_str == '+')
			flag->plus = 1;
		else if (*point_str == '0')
			flag->zero = 1;
		else if (*point_str == '#')
			flag->sharp = 1;
		else if (*point_str == 'l')
			flag->longg = 1;
		else if (*point_str == 'h')
			flag->shortt = 1;
		point_str++;
	}
	return ((char*)point_str);
}

static char	*split_wid_acc(const char *point_str, int *n)
{
	*n = 0;
	while (ft_isdigit(*point_str))
	{
		*n *= 10;
		*n += *point_str - '0';
		point_str++;
	}
	return ((char*)point_str);
}

static char	*fill_width(const char *point_str, t_flags *flag,
		va_list *arg)
{
	while (ft_isflag(*point_str) || ft_isdigit(*point_str) ||
			*point_str == '*')
	{
		point_str = check_flags(point_str, flag);
		if (*point_str == '*')
		{
			flag->width = va_arg(*arg, int);
			if (flag->width < 0)
			{
				flag->minus = 1;
				flag->width *= -1;
			}
			point_str++;
		}
		if (ft_isdigit(*point_str))
			point_str = split_wid_acc(point_str, &(flag->width));
	}
	return ((char*)point_str);
}

static char	*fill_accuracy(const char *point_str, t_flags *flag,
		va_list *arg)
{
	while (*point_str == '.')
	{
		flag->dot = 1;
		point_str++;
		while (ft_isflag(*point_str) || ft_isdigit(*point_str) ||
				*point_str == '*')
		{
			if (*point_str == '*')
			{
				flag->accuracy = va_arg(*arg, int);
				if (flag->accuracy < 0)
				{
					flag->accuracy = 0;
					flag->dot = 0;
				}
				point_str++;
			}
			else if (ft_isdigit(*point_str))
				point_str = split_wid_acc(point_str, &(flag->accuracy));
			if (ft_isflag(*point_str) || ft_isdigit(*point_str) ||
					*point_str == '*')
				point_str = fill_width(point_str, flag, arg);
		}
	}
	return ((char*)point_str);
}

char		*check_width(const char *point_str, t_flags *flag,
		va_list *arg)
{
	point_str = fill_width(point_str, flag, arg);
	point_str = fill_accuracy(point_str, flag, arg);
	return ((char*)point_str);
}
