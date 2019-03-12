/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 06:19:22 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/12 00:44:03 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define U_MAX 2147483647
# define N_MAX 99

# define I(nbr)  (nbr - '0')
# define C(nbr) (nbr % 10) + '0'
# define ABS(x) ((x > 0) ? x : -x)

# include "libft.h"
# include "structs.h"
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>

void			ft_debug(void);
int				ft_printf(const char *format, ...);
int				ft_get_format(va_list ap, char *flags, char c);

char    		*ft_ldouble_format(int preci, long double nb);
int				ft_size_base(long long int n, int base);
char			*ft_strcapitalize(char *str);
char			*ft_itoa_base(long long int n, int base);
long double		ft_fabs(long double base);
long double		ft_pow(long double base, int puiss);
char			*ft_ftoa(double n, int precison);

void			print_double(t_double *d);
char			*ft_pre_cal(t_double *d);
char			*ft_l_pre_cal(t_l_double *d);

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

char			*ft_strleftjoin(char *str, char *buffer, int width);
char			*ft_strrightjoin(char *str, char *buffer, int width);
char			*ft_handle_precision(char *buffer, int prec);

t_conv			*ft_new_conversion(char *str);
char			*ft_parse_conversion(char *str, t_conv *conv);
char			*ft_print_conversion(char *str, va_list ap);
void			ft_print_float_conv(t_conv *conv, va_list ap);
char			*ft_get_float_signed(t_conv *conv, va_list ap);
intmax_t		ft_get_conv_signed(t_conv *conv, va_list ap);
uintmax_t		ft_get_conv_unsigned(t_conv *conv, va_list ap);
void			ft_del_conversion(t_conv *conv);

void			ft_print_u(t_conv *conv, uintmax_t num);
void			ft_print_o(t_conv *conv, uintmax_t num);
void			ft_print_x(t_conv *conv, uintmax_t num);
void			ft_print_x_caps(t_conv *conv, uintmax_t num);
void			ft_print_wint(wint_t wint);
void			ft_print_wstr(t_conv *conv, wchar_t *wstr);
void			ft_print_wchar(t_conv *conv, wint_t wint);
void			ft_print_char(t_conv *conv, char c);
void			ft_print_str(t_conv *conv, char *str);
void			ft_print_spacing(int len, int min, char c);
void			ft_print_num_spaced(t_conv *conv, char *str);
int				ft_tally_get(int size, int add);
int				ft_tally_print(void *mem, int size);
void			ft_tally_str(char *str);
uintmax_t		ft_digitc(uintmax_t n);

void			ft_printf_error(char *str);
#endif
