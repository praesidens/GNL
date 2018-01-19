/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:19:45 by bsuprun           #+#    #+#             */
/*   Updated: 2018/01/19 20:08:11 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static t_list	ft_fd_search(const int fd, t_list **lst)
{
	if (fd && *lst && lst)
	{
		t_list		*tmp_lst;

		tmp_lst = *lst;
		while (tmp_lst)
		{
			if (tmp_lst->content_size == fd)
				return (tmp_lst);
			tmp_lst = tmp_lst->next;
		}
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(lst, tmp_lst);
	tmp_lst = *lst;
	return (tmp_lst);
}

static int		ft_ret_pos_of_ch_and_copy(char	**dest, char *src, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] && src[i] != c)
		i++;
	if (!(*dest = ft_strnew(i)))
		return (0);
	while (src[j] && src[j] != c)
	{
		*dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static t_list		*lst;
	t_list				*temp_lst;
	char				buf[BUFF_SIZE + 1];
	int					ret;
	int					i;

	if ((fd < 0 || !line || read(fd, buf, 0) < 0))
		return (-1);
	temp_lst = ft_fd_search(&lst, fd);
	CHECK_MALLOC((*line = ft_strnew(1)));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		CHECK_MALLOC((temp_lst->content = ft_strjoin(temp_lst->content, buf)));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(temp_lst->content))
		return (0);
	i = ft_ret_pos_of_ch_and_copy(line, temp_lst->content, '\n');
		

	return (1);
}

int		main(void)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
	return (0);
}
