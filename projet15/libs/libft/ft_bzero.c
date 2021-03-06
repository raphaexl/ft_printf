/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:22:17 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/13 17:26:00 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*p;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}
