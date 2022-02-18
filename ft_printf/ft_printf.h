/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 19:37:27 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/20 18:23:32 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_flags
{
	int				space;
	int				minus;
	int				plus;
	int				zero;
	int				dot;
	int				sharp;
	int				width;
	int				accuracy;
	int				longg;
	int				shortt;
}					t_flags;

typedef struct		s_specifier
{
	int				d;
	long int		ld;
	short int		hd;
	char			*s;
	double			g;
	void			*p;
	int				*n;
}					t_specifier;

void				*ft_memcpy(void *restrict dest, const void *restrict srt,
		size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *restrict dest,
		const char *restrict src, size_t size);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isflag(int c);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putnbr(int n);
void				ft_putnbr_long(long int n);
void				ft_putnbr_short(short int n);
void				ft_putnbr_un(unsigned int n);
void				ft_putnbr_un_long(unsigned long int n);
void				ft_putnbr_un_short(unsigned short int n);
void				ft_putnchar(char c, int n);
char				*check_flags(const char *point_str, t_flags *flag);
char				*check_width(const char *point_str, t_flags *flag,
		va_list *arg);
int					separation_int(t_specifier *spec, t_flags *flag,
		va_list *arg);
int					separation_int_un(t_specifier *spec, t_flags *flag,
		va_list *arg);
int					separation_x(t_specifier *spec, t_flags *flag,
		va_list *arg);
int					separation_bigx(t_specifier *spec, t_flags *flag,
		va_list *arg);
void				flag_null(t_flags *flag);
void				big_x(char *str);
int					print_str(const char *s, t_flags *flag);
int					print_int(int d, t_flags *flag);
int					print_int_long(long int d, t_flags *flag);
int					print_int_short(short int d, t_flags *flag);
int					print_c(const int c, t_flags *flag);
int					print_un_int(int u, t_flags *flag);
int					print_un_int_long(long int u, t_flags *flag);
int					print_un_int_short(short int u, t_flags *flag);
int					print_x(int x, t_flags *flag);
int					print_x_long(unsigned long int x, t_flags *flag);
int					print_x_short(unsigned short int x, t_flags *flag);
int					print_bigx(int x, t_flags *flag);
int					print_bigx_long(long int x, t_flags *flag);
int					print_bigx_short(short int x, t_flags *flag);
int					print_p(void *p, t_flags *flag);
int					no_minus_print_help(int i, int n, t_flags *flag);
int					amount_numbers(long long d);
int					amount_numbers_un(unsigned long long d);
int					amount_numbers_dec16(size_t d);
char				*ft_adress(void *adr);
char				*ft_itoa_base(int d, int base);
char				*ft_itoa_base_l(long int d, int base);
char				*ft_itoa_base_h(short int d, int base);
int					split_print_1(const char *point_form,
		t_specifier *spec, t_flags *flag, va_list *hui);
int					split_print_2(const char *point_form,
		t_specifier *spec, t_flags *flag, va_list *hui);
int					split_print_3(const char *point_form,
		t_specifier *spec, t_flags *flag, va_list *hui);
int					split_print_4(const char *point_form,
		t_specifier *spec, t_flags *flag, va_list *hui);

#endif
