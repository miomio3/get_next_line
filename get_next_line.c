#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		p[i++] = *s1++;
	while (*s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;

	p = (void *)malloc(size * n);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, size * n);
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
	if (size != 0)
		*d = '\0';
	return (ft_strlen(s));
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
		tmp = ft_substr(buf, 0, ft_strlen(p) - 1);
		tmp2 = ft_strjoin(*line, tmp);
		free (tmp);
		tmp = ft_substr(p + 1, 0, ft_strlen(p + 1));
		ft_strlcpy(buf, tmp, ft_strlen(tmp));
		f = 0;
	}
	else
	{
		tmp2 = ft_strjoin(*line, buf);
		ft_memset(buf, 0, BUFFER_SIZE + 1);
		f = 1;
	}
	free(tmp);
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
		buf = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	i = 0;
	while (f)
	{
		if (buf[0] != '\0')
			f = create_line(&line, buf);
		if (f == 1)
		{
			if (read(fd, buf, BUFFER_SIZE) <= 0)
			{
				if (i++ == 0)
					return (NULL);
				break ;
			}
		}
	}
	return (line);
}
