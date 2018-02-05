/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:09:34 by bsuprun           #+#    #+#             */
/*   Updated: 2017/11/07 17:17:49 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!(*needle))
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		k = i;
		j = 0;
		while (haystack[k] == needle[j] && needle[j] && k < len)
		{
			k++;
			j++;
		}
		if (!(needle[j]))
			return ((char*)&haystack[k - j]);
		i++;
	}
	if (*haystack == '\0' && *needle == '\0')
		return ((char *)haystack);
	return (NULL);
}
