/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:02:57 by bsuprun           #+#    #+#             */
/*   Updated: 2017/11/01 17:02:23 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
			c == '\v' || c == '\f' || c == '\r');
}

int			ft_atoi(const char *str)
{
	int					i;
	unsigned long int	n;
	int					sign;

	i = 0;
	n = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		n = (10 * n) + (str[i] - '0');
		if (n >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (n > 9223372036854775807 && sign == -1)
			return (0);
		i++;
	}
	return (sign * n);
}
