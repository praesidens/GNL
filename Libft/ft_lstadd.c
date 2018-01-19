/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:14:32 by bsuprun           #+#    #+#             */
/*   Updated: 2017/11/09 17:42:22 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst != NULL && new)
	{
		if (*alst == NULL)
		{
			*alst = new;
			(*alst)->next = NULL;
		}
		else
		{
			new->next = *alst;
			*alst = new;
		}
	}
}
