/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 09:41:46 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/12 14:40:23 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	STRUCTS_H
# define STRUCTS_H

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

typedef unsigned int	t_uint;

typedef enum			e_modifier
{
	NONE, HH, H, LL, L, J, Z, LF
} t_modifier;

typedef	struct	s_flag
{
	int		hash;
	int		space;
	int		plus;
	int		minus;
	int		zero;
}				t_flag;

typedef struct			s_conv
{
	char				*start;
	t_flag				*flag;
	char				sep;
	int					min_width;
	int					precision;
	int					prec_set;
	int					width_star_set;
	int					prec_star_set;
	t_modifier			modif;
	char				type;
	char				sign;
}						t_conv;

#endif
