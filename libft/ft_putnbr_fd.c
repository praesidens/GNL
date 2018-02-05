/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:29:26 by bsuprun           #+#    #+#             */
/*   Updated: 2017/11/02 20:39:49 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int n1;

	n1 = (long int)n;
	if (n1 < 0)
	{
		ft_putchar_fd('-', fd);
		n1 = -n1;
	}
	if (n1 >= 10)
	{
		ft_putnbr_fd(n1 / 10, fd);
		ft_putchar_fd(n1 % 10 + '0', fd);
	}
	if (n1 < 10)
		ft_putchar_fd(n1 % 10 + '0', fd);
}
