#include "get_next_line.h"

char	*listbuf_join(t_list **list)
{
	t_list	*t;
	t_list	*tmp_list;
	char	*line;
	char	*tmp;

	t = *list;
	line = ft_substr("", NULL);
	if (line == NULL)
		return (NULL);
	while (t)
	{
		if (t->next == NULL)
			t->buf = ft_substr(t->buf, ft_strchr(t->buf, '\n'));
		tmp = ft_strjoin(line, t->buf);
		free(line);
		if (tmp == NULL)
			return (NULL);
		line = tmp;
		tmp_list = t->next;
		free(t->buf);
		free(t);
		t = tmp_list;
	}
	return (line);
}

t_list	*front_list(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
		tmp = tmp->next;
	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp == NULL)
		free_list(list);
	return (*list);
}

int	free_list(t_list **list)
{
	t_list	*tmp;
	t_list	*t;

	while (t)
	{
		tmp = t->next;
		free(t->buf);
		free(t);
		t = tmp;
	}
	return (-1);
}

int	create_list(t_list **list, int fd)
{
	t_list	*tmp;

	while (tmp)
		tmp = tmp->next;
	if (tmp == NULL)
		return (-1);
	tmp->buf = (char *)ft_calloc(3 + 1, sizeof(char));
	if (tmp->buf == NULL)
		return (free_list(list));
	if (read(fd, tmp->buf, 3) <= 0)
		return (0);
	tmp->fd = fd;
	if (ft_strchr(tmp->buf, '\n') == NULL)
		return (1);
	else
		return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*tmp;
	int				f;

	f = 1;
	while (f)
	{
		tmp = front_list(&list);
		free(list);
		list = tmp;
		f = create_list(&list, fd);
		if (f == -1)
			return (NULL);
	}
	return (listbuf_join(&list));
}
