#include "get_next_line.h"

char	*listbuf_join2(t_list **list)
{
	char	*line;
	char	*tmp2;
	char	*p;

	line = ft_strjoin("", "");
	while (*list)
	{
		p = NULL;
		if ((*list)->next == NULL)
			p = ft_strchr((*list)->buf, '\n');
		if (p == NULL)
			join_free(list, &line, &(*list)->buf, p);
		else
		{
			tmp2 = ft_substr((*list)->buf, p);
			if (tmp2 == NULL)
				return (NULL);
			join_free(list, &line, &tmp2, p);
			free(tmp2);
			break ;
		}
	}
	return (line);
}

char	*listbuf_join(t_list **list, int f)
{
	char	*line;

	line = listbuf_join2(list);
	if (f == 2 && line != NULL)
	{
		if (*line == '\0')
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}

char	*free_list(t_list **list)
{
	t_list	**tmp;
	t_list	*t;

	while (*list)
	{
		tmp = &((*list)->next);
		free((*list)->buf);
		t = *list;
		free(t);
		list = tmp;
	}
	return (NULL);
}

int	create_list(t_list **tmp, int fd)
{
	unsigned char	*p;
	size_t			i;

	(*tmp)->buf = malloc((10 + 1) * sizeof(char));
	if ((*tmp)->buf == NULL)
		return (-1);
	p = (unsigned char *)(*tmp)->buf;
	i = 0;
	while (i < 10 + 1)
	{
		p[i] = '\0';
		i++;
	}
	(*tmp)->fd = fd;
	if (read(fd, (*tmp)->buf, 10 ) <= 0)
		return (2);
	if (ft_strchr((*tmp)->buf, '\n') == NULL)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			**tmp;
	int				f;
	char			*line;

	f = 1;
	tmp = &list;
	while (f && f != 2)
	{
		if (*tmp != NULL)
			if (ft_strchr((*tmp)->buf, '\n') != NULL)
				break ;
		while (*tmp)
			tmp = &((*tmp)->next);
		*tmp = malloc(sizeof(t_list));
		if (*tmp == NULL)
			return (free_list(&list));
		(*tmp)->next = NULL;
		f = create_list(tmp, fd);
		if (f == -1)
			return (free_list(&list));
	}
	line = listbuf_join(&list, f);
	return (line);
}
