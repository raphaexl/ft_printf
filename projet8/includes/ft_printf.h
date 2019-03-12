/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 06:19:22 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/06 19:41:35 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define UINT_MAX 4294967295
# define I(nbr)  (nbr - '0')
# define C(nbr) (nbr % 10) + '0'
# define ABS(x) ((x > 0) ? x : -x)

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_data
{
	long	mantissa:52;
	long	exponent:11;
	long	sign:1;
}				t_data;

typedef struct	s_data_l
{
	long	mantissa:63;
	long	b_63:1;
	long	exponent:15;
	long	sign:1;
}				t_data_l;

typedef union	u_double
{
	t_data		data;
	double		d;
}				t_double;

typedef union	u_l_double
{
	t_data_l	data;
	long double	d;
}				t_l_double;

typedef struct	s_sum
{
	int		i;
	int		j;
	int		sm;
}				t_sum;

typedef	struct	s_flag
{
	int		prec;
	int		width;
	int		hash;
	int		space;
	int		plus;
	int		minus;
	int		zero;
	int		size;
}				t_flag;

void			ft_debug(void);
char			*ft_double(long double n, int precision);
char			*ft_double(long double n, int precision);
int				ft_printf(char *format, ...);
int				ft_get_format(va_list ap, char *flags, char c);

char    		*ft_ldouble_format(int preci, long double nb);
int				ft_size_base(long long int n, int base);
char			*ft_strcapitalize(char *str);
char			*ft_itoa_base(long long int n, int base);
long double		ft_fabs(long double base);
long double		ft_pow(long double base, int puiss);
char			*ft_ftoa(double n, int precison);

char			*ft_print_intformat(va_list ap, char *flag);
char			*ft_print_uintformat(va_list ap, char *flag);
char			*ft_print_pformat(va_list ap, char *flag);
char			*ft_print_octalformat(va_list ap, char *flag);
char			*ft_print_hexaformat(va_list ap, char *flag, int c);

char			*ft_print_charformat(va_list ap, char *flag);
char			*ft_print_strformat(va_list ap, char *flag);
char			*ft_print_floatformat(va_list ap, char *flag);
char			*ft_print_percentformat(va_list ap, char *flag);
char			*ft_print_doubleformat(va_list ap, char *flag);
char			*ft_print_ldoubleformat(va_list ap, char *flag);

void			print_double(t_double *d);
char			*ft_pre_cal(t_double *d);
char			*ft_l_pre_cal(t_l_double *d);
char			*ft_ldouble(long double n, int precison);
char			*ft_print_floatformat(va_list ap, char *flag);

char			*ft_strmulti(char* num1, char* num2);
char			*ft_exposant(int a, int n);
char			*ft_stradd(char *str1, char *str2);

void			ft_print_mantissa(long nbr);
void			ft_print_exposant(long nbr);
void			ft_print_l_mantissa(long nbr);
void			ft_print_l_exposant(long nbr);
void			ft_print_l_sign(long nbr);
void			ft_print_l_test(long nbr);
void			print_l_double(t_l_double *d);
char			*ft_double_cal(t_double *d);
char			*ft_l_double_cal(t_l_double *d);
char			*ft_strrev(char *str);
void			ft_swap(int *x, int *y);
void			ft_swapstr(char **str1, char **str2);

void			ft_init_flags(t_flag *g);
int				ft_process_flags(t_flag *f, char *str);
int				ft_apply_format(t_flag *f, char	*buffer, char c);
int				ft_process_formati(t_flag *f, char *buffer);
int				ft_process_formatuox(t_flag *f, char *buffer);
int				ft_process_formatf(t_flag *f, char *buffer);
int				ft_process_formate(t_flag *f, char *buffer);
int				ft_process_formatg(t_flag *f, char *buffer);
int				ft_process_formatc(t_flag *f, char *buffer);
int				ft_process_formats(t_flag *f, char *buffer);
int				ft_process_formatp(t_flag *f, char *buffer);
int				ft_process_format1(t_flag *f, char *buffer);
char			*ft_strleftjoin(char *str, char *buffer, int width);
char			*ft_strrightjoin(char *str, char *buffer, int width);
char			*ft_handle_precision(char *buffer, int prec);
#endif
