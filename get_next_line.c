#include "get_next_line.h"

void	join_free(t_list **list, char **line, char *tmp2)
{
	t_list	*t;
	char	*tmp;

	tmp = ft_strjoin(*line, tmp2);
	free(tmp2);
	free(*line);
	*line = tmp;
	t = (*list)->next;
	free(*list);
	*list = t;
}

char	*listbuf_join(t_list **list)
{
	char	*p;
	char	*line;
	char	*tmp;
	char	*tmp2;
	t_list	*t;

	line = ft_strjoin("", "");
	while ((*list)->next)
	{
		p = ft_strchr((*list)->buf, '\n');
		if (p == NULL)
			join_free(list, &line, (*list)->buf);
		else
		{
			tmp2 = ft_substr((*list)->buf, p);
			 	if (tmp2 == NULL)
				 	return (NULL);
			join_free(list, &line, tmp2);
		}
	}
	free(*list);
	return (line);
}

int	free_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		free((*list)->buf);
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	return (-1);
}

int	create_list(t_list **list, int fd)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(t_list));
	if (tmp->next == NULL)
		return (free_list(list));
	tmp->buf = ft_calloc(10 + 1, sizeof(char));
	if (tmp->buf == NULL)
		return (free_list(list));
	tmp->fd = fd;
	if (read(fd, tmp->buf, 10) <= 0)
		return (0);
	if (ft_strchr(tmp->buf, '\n') == NULL)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	int				f;

	f = 1;
	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	while (f)
	{
		f = create_list(&list, fd);
		if (f == -1)
			return (NULL);
	}
	return (listbuf_join(&list));
}
