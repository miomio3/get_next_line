#include "get_next_line.h"

void	join_free(t_list **list, char **line, char **tmp2, char *p)
{
	t_list	*t;
	char	*tmp;
	char	*tmp1;

	tmp = ft_strjoin(*line, *tmp2);
	free(*line);
	*line = tmp;
	if (p == NULL)
	{
		t = (*list)->next;
		free((*list)->buf);
		free(*list);
		*list = t;
	}
	else
	{
		tmp1 = ft_strjoin(p + 1, "");
		free((*list)->buf);
		(*list)->buf = tmp1;
	}
}

char	*listbuf_join(t_list **list)
{
	char	*p;
	char	*line;
	char	*tmp2;

	line = ft_strjoin("", "");
	while (*list)
	{
		if ((*list)->next == NULL)
			p = ft_strchr((*list)->buf, '\n');
		else
			p = NULL;
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
	(*tmp)->buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if ((*tmp)->buf == NULL)
		return (-1);
	(*tmp)->fd = fd;
	if (read(fd, (*tmp)->buf, BUFFER_SIZE ) <= 0)
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
	line = listbuf_join(&list);
	if (f == 2 && line == "abc")
	{
		free(line);
		return (NULL);
	}
	return (line);
}
