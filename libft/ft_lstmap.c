/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:15:27 by bsuprun           #+#    #+#             */
/*   Updated: 2017/11/07 15:51:31 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*new;
	t_list	*p_rand;

	if (lst != NULL && f != NULL)
	{
		if (!(temp = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		temp = f(lst);
		new = ft_lstnew(temp->content, temp->content_size);
		p_rand = new;
		lst = lst->next;
		while (lst != NULL)
		{
			temp = f(lst);
			new->next = ft_lstnew(temp->content, temp->content_size);
			new = new->next;
			lst = lst->next;
			temp = temp->next;
		}
		new->next = NULL;
		return (p_rand);
	}
	return (NULL);
}
