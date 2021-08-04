#include "get_next_line.h"

t_list	*front_list(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int	free_list(t_list **list)
{
	t_list	*tmp;
	t_list	*t;

	while (t)
	{
		tmp = t;
		tmp = tmp->next;
		free(t->buf);
		free(t);
		t = tmp;
	}
	return (-1);
}

char	*create_list(t_list **list, int fd)
{
	t_list	*tmp;

	tmp = front_list(list);
	tmp->buf = (char *)malloc(3 + 1);
	if (tmp->buf == NULL)
		return (free_list(&list));//-1=error,NULLをreturn
	if (read(fd, tmp->buf, 3) <= 0)
		return (free_list(&list));//上に同じ
	tmp->fd = fd;
	printf("%d\n", tmp->fd);//
	printf("%s\n", tmp->buf);//
	if (ft_strchr(tmp->buf, '\n') == NULL)
		return (1);//1=list->をstrjoinしていく
	return (0);
}

t_list	*list_new(const t_list **list)
{
	t_list	*tmp;

	tmp = front_list(list);
	tmp = tmp->next;
	tmp = (t_list *)malloc(sizeof(t_list));
	return (list);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*new_list;
	char			*line;
	int				f;

	f = 1;
	while (f)
	{
		f = create_list(&list, fd);
		if (f == -1)
			return (NULL);
		else if (f == 0)
			return (listbuf_join(&list));
	}
}

int	main(void)
{
	int		fd;
	char	buf[100];

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("fail\n");
		return (-1);
	}
	printf("%s", get_next_line(fd));
}
