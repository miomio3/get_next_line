#include "get_next_line.h"

char	*listbuf_join(t_list **list)
{
	char	*p;
	char	*line;
	char	*tmp;
	char	*tmp2;
	t_list	*t;

	while (*list)
	{
		p = strchr((*list)->buf, '\n');
		if (p == NULL)
			tmp = strjoin(line, (*list)->buf);
		else
		{
			tmp2 = substr((*list)->buf, p);
			 	if (tmp2 == NULL)
				 	return (NULL);
			tmp = strjoin(line, tmp2);
		}
		if (tmp == NULL)
			return (NULL);
		free(line);
		line = tmp;
		t = (*list)->next;
		free(*list);
		*list = t;
	}
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
	while (*list)
		*list = (*list)->next;
	*list = malloc(sizeof(t_list));
	if (*list == NULL)
		return (-1);
	(*list)->buf = ft_calloc(3 + 1, sizeof(char));
	if ((*list)->buf == NULL)
		return (-1);
	(*list)->fd = fd;
	if (read(fd, (*list)->buf, 3) <= 0)
		reuturn (0);
	if (strchr((*list)->buf, '\n') == NULL)
		return (1);
	else
		return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	int				f;

	f = 1;
	while (f)
	{
		f = create_list(&list, fd);
		if (f == 0)
			break ;
		else if (f == -1)
			return (NULL);
	}
	return (listbuf_join(&list));
}
