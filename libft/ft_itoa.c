/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:03:15 by bsuprun           #+#    #+#             */
/*   Updated: 2017/11/09 17:38:52 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(unsigned int n)
{
	unsigned int i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	unsigned int	n1;
	int				i;
	int				sign;
	int				len;
	char			*str;

	sign = (n < 0) ? 1 : 0;
	n1 = (n < 0) ? (n + 1) * (-1) + 1 : n;
	len = ft_intlen(n1);
	if (!(str = (char *)malloc((sizeof(char) * (len + sign + 1)))))
		return (NULL);
	i = len - 1 + sign;
	str[len + sign] = 0;
	if (sign)
		str[0] = '-';
	while (i >= sign)
	{
		str[i--] = n1 % 10 + '0';
		n1 = n1 / 10;
	}
	return (str);
}
