/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:17:35 by bsuprun           #+#    #+#             */
/*   Updated: 2018/02/02 18:19:07 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int				ft_nl(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}



int				ft_reader(int fd, t_list **lst)
{
	char	buf[BUFF_SIZE + 1];
	char	*buf1;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		buf1 = (*lst)->C;
		(*lst)->C = ft_strjoin((*lst)->C, buf);
		ft_strdel(&buf1);
	}
	printf("(*lst)->C: %s\n", (*lst)->C);
	return (ret);
}

int				ft_splitter(t_list **lst, char **line)
{
	if (ft_strchr((*lst)->C, '\n'))
	{
		*line = ft_strsub((*lst)->C, 0, ft_nl((*lst)->C));
		printf("LINE V IF:%s\n", *line);
		(*lst)->C = ft_strsub((*lst)->C, ft_nl((*lst)->C) + 1,
			   	ft_strlen((*lst)->C - ft_nl((*lst)->C)));
		printf("IF\n");
		printf("(*lst)->C V IF: %s\n", (*lst)->C);
		return (1);
	}
	else if (!ft_strchr((*lst)->C, '\n' && ft_strlen((*lst)->C) > 0))
	{
		printf("ELSE IF\n");
		*line = (*lst)->C;
		(*lst)->C = ft_strsub((*lst)->C, 0, 0);
		return (1);
	}
	else
		return (0);
}


int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
//	int				ret;

	if (fd < 0 || !line)
		return (-1);
	//while (lst && (lst->C_S != (size_t)fd))
	//	lst = lst->next;
	if (!lst && (lst = ft_lstnew("", 1)))
		lst->C_S = fd;
	if (ft_strlen(lst->C) < 1)
		ft_reader(fd, &lst);
	return (ft_splitter(&lst, line));
}


int		main(int ac, char **av)
{
	char	*line;
	int		fd;
//	int		fd1;
//	int		fd2;

//	test = "abcd'\n'assjjs";
//	c = '\n';
	
	if (ac != 2)
	{
		printf("VIBERI TXT\n");
		return (1);
	}
//	printf("CHAR POS: %i\n", ft_stringchr(test, c));
	fd = open(av[1], O_RDONLY);
//	fd1 = open("test1.txt", O_RDONLY);
//	fd2 = open("test2.txt", O_RDONLY);

	int		i = 1;
	while ((i = get_next_line(fd, &line) > 0))
		printf("%s\n", line);

	return (0);
}

