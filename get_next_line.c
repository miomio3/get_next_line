#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buf[100];
	size_t	i;
	size_t	ret;
	char	*p;
	char	*line;

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret <= 0)
		return (NULL);
	i = 0;
	p = ft_strchr(buf, '\n');
	if (line == NULL)
		return (NULL);
	if (p != NULL)
	{
		while (&buf[i] != p)
			i++;
		line = ft_substr(buf, 0, i);
	}
	else
		line = ft_substr(buf, 0, ft_strlen(buf));
	return (line);
}
