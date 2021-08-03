#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		p[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		p[i] = *s2++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			j;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == NULL || src == NULL)
		return (0);
	j = 0;
	while (j++ < size && *s)
		*d++ = *s++;
	*d = '\0';
	return (ft_strlen(src));
}

int	create_line(char **line, char *buf)
{
	char	*p;
	char	*tmp;
	char	*tmp2;
	int		f;

	p = ft_strchr(buf, '\n');
	if (p != NULL)
	{
		tmp = ft_substr(buf, 0, ft_strlen(buf) - ft_strlen(p) + 1);
		if (tmp == NULL)
			return (3);
		tmp2 = ft_strjoin(*line, tmp);
		free(tmp);
		if (tmp2 == NULL)
			return (3);
		ft_strlcpy(buf, p + 1, ft_strlen(p + 1));
		f = 0;
	}
	else
	{
		tmp2 = ft_strjoin(*line, buf);
		if (tmp2 == NULL)
			return (3);
		ft_memset(buf, 0, BUFFER_SIZE);
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

	f = 2;
	line = ft_substr("", 0, 0);
	if (buf == NULL)
		buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (line == NULL || buf == NULL)
		return (NULL);
	while (f)
	{
		if (buf[0] == '\0')
		{
			if (read(fd, buf, BUFFER_SIZE) <= 0)
			{
				if (f == 2)
				{
					free(buf);
					buf = NULL;
					free(line);
					return (NULL);
				}
				break ;
			}
		}
		f = create_line(&line, buf);
		if (f == 3)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}
