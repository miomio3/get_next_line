#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*p;
	char		*line;
	size_t		i;

	if (buf == NULL)
		buf = (char *)malloc(sizeof(char) * 100);
	line = "";
	while (read(fd, buf, 100) >= 0)
	{
		p = ft_strchr(buf, '\n');
		i = 1;
		while (&buf[i] != p && p != NULL)
			i++;
		if (p == NULL)
			i = ft_strlen(buf) + 1;
		line = ft_strjoin(line, ft_substr(buf, 0, i - 1));
		if (p != NULL)
		{
			buf = ft_strdup(p + 1);
			break ;
		}
		else
		{
			buf = NULL;
			break ;
		}
	}
	free(buf);
	return (line);
}
