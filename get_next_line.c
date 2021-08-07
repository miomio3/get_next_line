#include "get_next_line.h"

void	join_free(t_list **list, char **line, char *tmp2, char *p)
{
	t_list	*t;
	char	*tmp;

	tmp = ft_strjoin(*line, tmp2);
	free(tmp2);
	free(*line);
	*line = tmp;
	if (p == NULL)
	{
		t = (*list)->next;
		free(*list);
		*list = t;
	}
	else
	{
		free((*list)->buf);
		(*list)->buf = ft_strjoin(p + 1, "");
	}
}

char	*listbuf_join(t_list **list)
{
	char	*p;
	char	*line;
	char	*tmp;
	char	*tmp2;
	t_list	*t;

	line = ft_strjoin("", "");
	while (*list)
	{
		p = ft_strchr((*list)->buf, '\n');
		if (p == NULL)
			join_free(list, &line, (*list)->buf, p);
		else
		{
			tmp2 = ft_substr((*list)->buf, p);
			 	if (tmp2 == NULL)
				 	return (NULL);
			join_free(list, &line, tmp2, p);
			break ;
		}
	}
	return (line);
}

int	free_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	return (-1);
}

int	create_list(t_list **tmp, int fd)
{
	(*tmp)->buf = ft_calloc(10 + 1, sizeof(char));
	if ((*tmp)->buf == NULL)
		return (-1);
	(*tmp)->fd = fd;
	if (read(fd, (*tmp)->buf, 10) <= 0)
		return (0);
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
	while (f)
	{
		if (*tmp != NULL)
			if (ft_strchr((*tmp)->buf, '\n') != NULL)
				break ;
		while (*tmp)
			*tmp = (*tmp)->next;
		*tmp = malloc(sizeof(t_list));
		if (*tmp == NULL)
			return (NULL);
		f = create_list(tmp, fd);
		if (f == -1)
			return (NULL);
	}
	line = listbuf_join(&list);
	return (line);
}
