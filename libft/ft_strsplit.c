/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:09:46 by bsuprun           #+#    #+#             */
/*   Updated: 2017/12/26 21:25:43 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s, char c)
{
	int		word_count;
	int		i;

	i = 1;
	word_count = 0;
	while (s[i])
	{
		if (i == 1 && s[i - 1] != c)
			word_count++;
		if (s[i] && s[i - 1] == c && s[i] != c)
			word_count++;
		i++;
	}
	return (word_count);
}

char		**ft_strsplit(char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**p_s;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(p_s = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[i] != c && s[i])
			i++;
		p_s[j] = ft_strsub(s, k, i - k);
		if ((int)j < count_words(s, c))
			j++;
		i++;
	}
	p_s[j] = 0;
	return (p_s);
}
