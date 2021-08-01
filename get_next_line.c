#include "get_next_line.h"

static int	create_line(char **line, char **buf)
{
	char	*p;
	size_t	i;
	char	*tmp;

	p = ft_strchr(*buf, '\n');
	i = 0;
	if (p != NULL)
		i = ft_strlen(*buf) - ft_strlen(p);
	else
		i = ft_strlen(*buf);
	tmp = ft_substr(*buf, 0, i);
	*line = ft_strjoin(*line, tmp);
	free(tmp);
	if (p != NULL)
		*buf = ft_strdup(p + 1);
	if (*buf[0] == '\0')
	{
		*buf = ft_calloc(100, sizeof(char));
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			f;

	line = "";
	f = 1;
	if (buf == NULL)
	{
		buf = (char *)malloc(sizeof(char) * 100);
		if (buf == NULL)
			return (NULL);
		if (read(fd, buf, 100) <= 0)
			line = NULL;
		f = create_line(&line, &buf);
	}
	while (f)
	{
		f = create_line(&line, &buf);
		if (f == 1)
			if (read(fd, buf, 100) <= 0)
				break ;
	}
	return (line);
}
