/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 19:32:42 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/20 18:44:02 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		split_print_1(const char *point_form, t_specifier *spec,
		t_flags *flag, va_list *arg)
{
	int	count;

	count = 0;
	if (*point_form == 'c')
	{
		spec->d = va_arg(*arg, int);
		count += print_c(spec->d, flag);
	}
	else if (*point_form == 's')
	{
		spec->s = va_arg(*arg, char*);
		count += print_str(spec->s, flag);
	}
	else if (*point_form == 'd' || *point_form == 'i')
		count += separation_int(spec, flag, arg);
	else
		count += split_print_2(point_form, spec, flag, arg);
	return (count);
}

int		split_print_2(const char *point_form, t_specifier *spec,
		t_flags *flag, va_list *arg)
{
	int count;

	count = 0;
	if (*point_form == 'u')
		count += separation_int_un(spec, flag, arg);
	else if (*point_form == 'p')
	{
		spec->p = va_arg(*arg, void*);
		count += print_p(spec->p, flag);
	}
	else if (*point_form == 'x')
		count += separation_x(spec, flag, arg);
	else if (*point_form == 'X')
		count += separation_bigx(spec, flag, arg);
	else if (*point_form == '%')
		count += print_c('%', flag);
	else if (*point_form != '\0')
		count += print_c(*point_form, flag);
	return (count);
}

int		ft_printf(const char *format, ...)
{
	int			count;
	char		*point_form;
	va_list		arg;
	t_flags		flag;
	t_specifier	spec;

	count = 0;
	va_start(arg, format);
	point_form = (char*)format;
	while (*point_form)
	{
		if (*point_form != '%')
		{
			ft_putchar(*point_form++);
			count++;
			continue ;
		}
		flag_null(&flag);
		point_form = check_width(++point_form, &flag, &arg);
		count += split_print_1(point_form, &spec, &flag, &arg);
		if (*point_form == '\0')
			break ;
		point_form++;
	}
	return (count);
}
