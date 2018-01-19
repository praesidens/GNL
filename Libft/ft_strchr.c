/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:55:31 by bsuprun           #+#    #+#             */
/*   Updated: 2017/11/01 19:49:35 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char		*a;
	size_t		i;

	i = 0;
	a = (char*)s;
	if (c == '\0')
	{
		while (a[i])
			i++;
		return ((char*)&a[i]);
	}
	while (a[i])
	{
		if ((unsigned char)a[i] == c)
		{
			a = (char*)&s[i];
			return ((char*)a);
		}
		i++;
	}
	return (NULL);
}
