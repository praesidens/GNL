/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:22:26 by bsuprun           #+#    #+#             */
/*   Updated: 2017/11/04 20:32:30 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*a;
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	while (i < start && *s)
		i++;
	if (!(a = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[i] && (len > 0))
	{
		a[j] = s[i];
		i++;
		j++;
		len--;
	}
	a[j] = '\0';
	return ((char*)a);
}
