/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:32:54 by bsuprun           #+#    #+#             */
/*   Updated: 2017/11/07 17:55:33 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (unsigned char*)s1;
	d2 = (unsigned char*)s2;
	while (n)
	{
		if (*d1 != *d2)
			return (*d1 - *d2);
		n--;
		d1++;
		d2++;
	}
	return (0);
}
