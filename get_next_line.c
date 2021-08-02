#include "get_next_line.h"

static int	create_line(char **line, char *buf)
{
	char	*p;
	size_t	i;
	char	*tmp;
	char	*tmp2;
	int		f;

	p = ft_strchr(buf, '\n');
	if (p != NULL)
	{
		tmp = ft_substr(buf, 0, ft_strlen(p) - 1);
		tmp2 = ft_strjoin(*line, tmp);
		free (tmp);
		tmp = ft_substr(p + 1, 0, ft_strlen(p + 1));
		ft_strlcpy(buf, tmp, ft_strlen(tmp));
		free(tmp);
		f = 0;
	}
	else
	{
		tmp = ft_substr(buf, 0, ft_strlen(buf));
		tmp2 = ft_strjoin(*line, tmp);
		ft_bzero(buf, 3 + 1);
		free(tmp);
		f = 1;
	}
	free(*line);
	*line = tmp2;
	return (f);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			f;
	size_t		i;

	f = 1;
	line = ft_strdup("");
	if (buf == NULL)
		buf = (char *)ft_calloc(4, sizeof(char));
	i = 0;
	while (f)
	{
		if (buf[0] != '\0' && i != 0)
			f = create_line(&line, buf);
		if (f == 1)
		{
			if (read(fd, buf, 3) <= 0)
			{
				if (i == 0)
					return (NULL);
				else
					break ;
			}
		}
		i++;
	}
	free(buf);
	return (line);
}
