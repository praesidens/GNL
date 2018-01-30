#include "get_next_line.h"

int		ft_chpos(char	*str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		splitter(t_list		**lst, char **line)
{
	if (ft_strchr((*lst)->content, '\n'))
	{
		*line = ft_strsub((*lst)->content, 0, ft_chpos((*lst)->content));
		(*lst)->content = ft_strsub((*lst)->content, ft_chpos((*lst)->content) + 1, ft_strlen((*lst)->content) - ft_chpos((*lst)->content));
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*buf1;

	if (fd <= 0 || !line || !fd)
		return (-1);
	while (lst && (lst->content_size != (size_t)fd))
		lst = lst->next;
	if (!lst)
	{
		lst = ft_lstnew("", 1);
		lst->content_size = fd;
	}
	if (((char*)lst->content)[0] && ft_strchr(lst->content, '\n'))
	{
		splitter(&lst, line);
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		buf1 = lst->content;
		lst->content = ft_strjoin(buf1, buf);
		ft_strdel(&buf1);
		if (splitter(&lst, line))
			return (1);
	}
	return (1);
}

/*
int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	fd = open(av[1], O_RDONLY);
	int		i = 1;
	while ((i = get_next_line(fd, &line) > 0))
		printf("%s\n", line);
	//get_next_line(fd, &line);
	//printf("%s\n", line);
	//get_next_line(fd, &line);
	//printf("%s\n", line);	

	return (0);
}
*/
