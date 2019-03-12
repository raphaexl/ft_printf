/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 06:19:22 by ebatchas          #+#    #+#             */
/*   Updated: 2019/01/29 15:14:10 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define UINT_MAX 4294967295

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_data
{
	long	mantissa:52;
	long	exponent:11;
	long	sign:1;
}				t_data;

typedef union	u_double
{
	t_data		data;
	double		d;
}				t_double;

int				ft_printf(char *format, ...);
int				ft_get_format(va_list ap, char *flags, char c);

char    		*ft_ldouble_format(int preci, long double nb);
int				ft_size_base(long long int n, int base);
char			*ft_strcapitalize(char *str);
char			*ft_itoa_base(long long int n, int base);
long double		ft_fabs(long double base);
long double		ft_pow(long double base, int puiss);
char			*ft_ftoa(double n, int precison);

int				ft_print_intformat(va_list ap, char *flag);
int				ft_print_uintformat(va_list ap, char *flag);
int				ft_print_pformat(va_list ap, char *flag);
int				ft_print_octalformat(va_list ap, char *flag);
int				ft_print_hexaformat(va_list ap, char *flag, int c);

int				ft_print_charformat(va_list ap, char *flag);
int				ft_print_strformat(va_list ap, char *flag);
int				ft_print_floatformat(va_list ap, char *flag);
int				ft_print_percentformat(va_list ap, char *flag);
int				ft_print_doubleformat(va_list ap, char *flag);

void			print_double(t_double *d);
char			*ft_ldouble(long double n, int precison);
int				ft_print_floatformat(va_list ap, char *flag);
#endif
