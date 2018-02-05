/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:02:48 by bsuprun           #+#    #+#             */
/*   Updated: 2018/02/05 13:48:21 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* *********************i***************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static int			ft_nl(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static int			ft_reader(int fd, t_list *lst)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*buf1;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		buf1 = lst->C;
		lst->C = ft_strjoin(lst->C, buf);
		ft_strdel(&buf1);
		if (ft_strchr(lst->C, '\n') || ret != BUFF_SIZE)
			return (ret);
	}
	return (ret);
}

static int			ft_splitter(t_list *lst, char **line)
{
	if (ft_strchr(lst->C, '\n'))
	{
		*line = ft_strsub(lst->C, 0, ft_nl(lst->C));
		lst->C = ft_strsub(lst->C, ft_nl(lst->C) + 1,
				ft_strlen(lst->C) - ft_nl(lst->C));
		return (1);
	}
	*line = ft_strdup(lst->C);
	ft_bzero(lst->C, ft_strlen(lst->C));
	return (**line ? 1 : 0);
}
	

int			get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*tmp;
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	ret = 1;
	tmp = lst;
	while (tmp && (tmp->C_S != (size_t)fd))
		tmp = tmp->next;
	if (!tmp && (tmp = ft_lstnew("", 1)))
	{
		tmp->C_S = fd;
		ft_lstadd(&lst, tmp);
	}
	if (tmp->C && !ft_strchr(tmp->C, '\n'))
		ret = ft_reader(fd, tmp);
	if (ret < 0)
		return (-1);
	if (tmp->C && ft_splitter(tmp, line))
		return (1);
	return (0);
}
