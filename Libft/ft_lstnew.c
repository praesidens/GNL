/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:12:32 by bsuprun           #+#    #+#             */
/*   Updated: 2017/11/03 21:04:56 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr_a;

	if (!(ptr_a = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!((void*)content))
	{
		ptr_a->content = NULL;
		ptr_a->content_size = 0;
	}
	else
	{
		if (!(ptr_a->content = malloc(content_size)))
		{
			free(ptr_a);
			return (NULL);
		}
		ft_memcpy(ptr_a->content, content, content_size);
		ptr_a->content_size = content_size;
	}
	ptr_a->next = NULL;
	return (ptr_a);
}
