#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		ft_stringchr(char	*str, char	c)
{
	int		i;
	
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	int				ret;
	char			*buf;
//	char			*buf1;

	if (fd < 0 || !line)
		return (-1);
	buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while (lst && (lst->content_size != (size_t)fd))
		lst = lst->next;
	if (!lst)
	{
//		printf("NOT LST\n");
		lst = ft_lstnew("", 1);
		lst->content_size = fd;
	}

/*	if (ft_strchr(lst->content, '\n'))
	{
		//printf("WE ARE IN FT_STRCHR\n");
		//printf("LST->CONTENT:%s\n", lst->content);
		*line = ft_strsub(lst->content, 0, ft_stringchr(lst->content, '\n'));
	//	printf("*LINE:%s\n", *line);
		lst->content = ft_strsub(lst->content, ft_stringchr(lst->content, '\n'), ft_strlen(lst->content) - ft_stringchr(lst->content, '\n'));
	}
	if (lst->content || ((ret = read(fd, buf, BUFF_SIZE) > 0)))
		return (1);
	if (!lst->content)
		return (0);
*/
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n'))
		{
			*line = ft_strsub(buf, 0, ft_stringchr(buf, '\n'));
			if (!lst->content)
				lst->content = ft_strsub(buf, ft_stringchr(buf, '\n'), ft_strlen(buf) - ft_stringchr(buf, '\n'));
			else
				lst->content = ft_strjoin(lst->content, ft_strsub(buf, ft_stringchr(buf, '\n'), ft_strlen(buf) - ft_stringchr(buf, '\n')));
			return (1);
		}
/*
		else
		{
			buf1 = lst->content;
			lst->content = ft_strjoin(buf, buf1);
			ft_strdel(&buf1);
			return (1);
		}
*/
/*	
		if (ft_strchr(buf, '\n'))
		{
			*line = ft_strsub(buf, 0, ft_stringchr(buf, '\n'));
			lst->content = ft_strsub(buf, ft_stringchr(buf, '\n'), ft_strlen(buf) - ft_stringchr(buf, '\n'));
			break ;
			return (1);
			*line = ft_strsub(buf, 0, ft_stringchr(buf, '\n'));
		//	if (lst->content)
		//		return (1);
		//	else
		//		return (0);
		}
*/
		/*
		else
		{
			buf1 = lst->content;
			lst->content = ft_strjoin(buf1, buf);
			ft_strdel(&buf1);
			return (0);
		}
		*/
		if (ret < 0 && !lst->content)
			return (0);
/*
		buf1 = lst->content;
		lst->content = ft_strjoin(lst->content, buf);
		ft_strdel(&buf1);
		if (ft_strchr(lst->content, '\n'))
		{
			*line = ft_strsub(lst->content, 0, ft_strlen(lst->content) - ft_stringchr(lst->content, '\n'));
			lst->content = ft_strsub(lst->content, ft_stringchr(lst->content, '\n'), ft_strlen(lst->content) - ft_strlen(*line));
			ft_strdel(&buf);
			return (1);
		}
*/
	}
	if (ret < 0 && !lst->content)
		return (0);
	return (-1);
}


int		main(void)
{
	char	*line;
//	char	*test;	
//	char	c;
	int		fd;

//	test = "abcd'\n'assjjs";
//	c = '\n';
	
//	printf("CHAR POS: %i\n", ft_stringchr(test, c));
	fd = open("test.txt", O_RDONLY);
	int		i = 1;

	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);

	return (0);
}
