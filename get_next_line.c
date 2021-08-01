#include "get_next_line.h"

static int	create_line(char **line, char buf[])
{
	char	*p;
	size_t	i;
	char	*tmp;

	p = ft_strchr(buf, '\n');
	i = 0;
	if (p != NULL)
	{
		i = ft_strlen(buf) - ft_strlen(p);
		tmp = ft_substr(buf, 0, i);
		*line = ft_strjoin(*line, tmp);
		free(tmp);
		ft_strlcpy(buf, p + 1, ft_strlen(p + 1) + 1);
	}
	else
	{
		i = ft_strlen(buf);
		tmp = ft_substr(buf, 0, i);
		*line = ft_strjoin(*line, tmp);
		free(tmp);
		ft_bzero(buf, 3);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
	char		*line;
	int			f;

	line = "";
	f = 2;
	if (buf[0] == '\0')
	{
		if (read(fd, buf, BUFFER_SIZE) <= 0)
			line = NULL;
		else
			f = create_line(&line, buf);
	}
	while (f)
	{
		if (f == 1)
		{
			if (read(fd, buf, BUFFER_SIZE) <= 0)
				break ;
		}
		f = create_line(&line, buf);
	}
	return (line);
}
