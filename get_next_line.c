/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:17:35 by bsuprun           #+#    #+#             */
/*   Updated: 2018/01/27 20:28:14 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int				ft_ttt(char *str)
{
	if (str[0] == '\0')
		return (1);
	else
		return (0);

}
int				ft_stringchr(char	*str)
{
	int		i;
	
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void			trim(t_list **lst, int len)
{
	char	*s;

	s = ft_strsub((*lst)->content, len + 1, ft_strlen((*lst)->content));
	ft_bzero((*lst)->content, ft_strlen((*lst)->content));
	free((*lst)->content);
	(*lst)->content = s;
	//free(s);
}

int			mamkin_coder(t_list *lst, char **line)
{
	int			i;

	i = ft_stringchr(lst->content);
	*line = ft_strsub(lst->content, 0, i);
	trim(&lst, i);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*buf1;

	if (fd < 0 || !fd || !line)
		return (-1);
	while (lst && (lst->content_size != (size_t)fd))
		lst = lst->next;
	if (!lst)
	{
		lst = ft_lstnew("", 1);
		lst->content_size = fd;
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		buf1 = lst->content;
		lst->content = ft_strjoin(buf1, buf);
		ft_strdel(&buf1);
	}
	//if ((char*)lst->content == '\0')
	//	 return (0);
	if (ft_ttt(lst->content))
		return (0);
	if (!ft_ttt(lst->content))
		mamkin_coder(lst, line);
	return (1);
	
}

/*
int		main(int ac, char **av)
{
	char	*line;
	int		fd;
//	int		fd1;
//	int		fd2;

//	test = "abcd'\n'assjjs";
//	c = '\n';
	
//	printf("CHAR POS: %i\n", ft_stringchr(test, c));
	fd = open(av[1], O_RDONLY);
//	fd1 = open("test1.txt", O_RDONLY);
//	fd2 = open("test2.txt", O_RDONLY);

	int		i = 1;
	while ((i = get_next_line(fd, &line) > 0))
	{
		printf("%s\n", line);
	}

	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);

//	get_next_line(fd1, &line);
//	printf("%s\n", line);
//	get_next_line(fd1, &line);
//	printf("%s\n", line);

//	get_next_line(fd2, &line);
//	printf("%s\n", line);
//	get_next_line(fd2, &line);
//	printf("%s\n", line);

	return (0);
}
*/
