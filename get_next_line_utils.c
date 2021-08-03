#include "get_next_line.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)buf;
	while (i < n)
		p[i++] = (unsigned char)ch;
	return (buf);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			break ;
		i++;
	}
	if ((unsigned char)s[i] != (unsigned char)c)
		return (NULL);
	return ((char *)s + i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_substr("", 0, 0));
	if (len < s_len - start)
		s_len = len;
	p = (char *)malloc(sizeof(char) * (s_len + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len && s [start + i])
	{
		p[i] = s[start + i];
		i++;
	}
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
