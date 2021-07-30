#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buf[30];
	char	*p;
	char	*line;
	size_t	i;
	size_t	bufsize;

	line = ft_strdup("");
	bufsize = BUFFER_SIZE / 30 + 1;
	while (bufsize-- && read(fd, buf, 30) > 0)
	{
		i = 0;
		while (ft_strchr("\n", buf[i]) == NULL && i <= 30)
			i++;
		p = ft_substr(buf, 0, i);
		if (p == NULL)
		{
			free(line);
			return (NULL);
		}
		line = ft_strjoin(line, p);
		free(p);
		if (ft_strchr("\n", buf[i]) != NULL)
			break ;
	}
	return (line);
}
