/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 19:39:17 by bsuprun           #+#    #+#             */
/*   Updated: 2017/11/04 21:35:49 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*a;
	size_t	i;
	size_t	j;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == len)
		return (ft_strnew(1));
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	if (!(a = (char*)malloc(sizeof(char) * (len - i) + 1)))
		return (NULL);
	if (s[i])
	{
		while (i < len)
			a[j++] = s[i++];
		a[j] = '\0';
	}
	return (a);
}
