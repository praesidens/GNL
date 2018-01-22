/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 20:29:12 by bsuprun           #+#    #+#             */
/*   Updated: 2018/01/22 21:08:11 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

/*
** We are trying to search file descriptor.
** We add file descriptor (if it doesn't exist).
** We also check fd, *lst and lst to avoid errors.
*/

static	t_list		*ft_fd_search(const int fd, t_list **lst)
{
	t_list			*t_lst;

	t_lst = *lst;
	while (t_lst)
	{
		if (t_lst->content_size == fd)
			return (t_lst);
		t_lst = t_lst->next;
	}
	free(t_lst);
	t_lst = ft_lstnew("\0", 1);
	t_lst->content_size = fd;
	ft_lstadd(lst, t_lst);
	free(t_lst);
	return (*lst);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*t_lst;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if ((fd < 0 || !line || read(fd, buf, 0) < 0))
		return (-1);
	CHECK_MALLOC((lst = ft_lstnew("\0", fd)));
	t_lst = ft_fd_search(fd, &lst);
	CHECK_MALLOC((*line = ft_strnew(1)));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		CHECK_MALLOC((lst->content = ft_strjoin(t_lst->content, buf)));
		if (ft_strchr(buf, '\n'))
		{
	//		*line = lst->content - ft_strchr(lst->content, '\n');
	//		lst->content += ft_strchr(lst->content, '\n');
			break ;
		}
	}
	if (ret < BUFF_SIZE && !ft_strlen(lst->content))
		return (0);
	return (1);
}

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	char	*str = "abcdefghijklmn";
	int		i;

	i = ft_strchr(str, 'a');
	printf("ETO I:%i\n", i);
//	while (get_next_line(fd, &line) == 1)
//	{
//		ft_putendl(line);
//		free(line);
//	}
	return (0);
}
