/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:13:59 by bsuprun           #+#    #+#             */
/*   Updated: 2017/11/09 17:41:34 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*next;

	if (alst != NULL && *alst != NULL && del != NULL)
	{
		current = *alst;
		while (current != NULL)
		{
			del(current->content, current->content_size);
			next = current->next;
			free(current);
			current = next;
		}
		*alst = NULL;
	}
}
