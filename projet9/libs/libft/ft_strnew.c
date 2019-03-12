/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:01:21 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/07 21:49:26 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;
	size_t	i;

	tab = NULL;
	if ((tab = (char *)malloc(1 + size)))
	{
		i = 0;
		while (i < size + 1)
		{
			tab[i] = '\0';
			i++;
		}
	}
	return (tab);
}
