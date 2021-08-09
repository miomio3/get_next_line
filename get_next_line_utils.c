#include "get_next_line.h"

char	*ft_substr(char const *s, const char *s1)
{
	char	*p;
	size_t	i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (*s == '\0')
		return (ft_substr("", NULL));
	if (s1 != NULL)
		s_len = s_len - ft_strlen(s1) + 1;
	p = (char *)malloc(sizeof(char) * (s_len + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < s_len && s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;

	i = 0;
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

void	join_free(t_list **list, char **line, char **tmp2, char *p)
{
	t_list	*t;
	char	*tmp;
	char	*tmp1;

	tmp = ft_strjoin(*line, *tmp2);
	free(*line);
	*line = tmp;
	if (p == NULL)
	{
		t = (*list)->next;
		free((*list)->buf);
		free(*list);
		*list = t;
	}
	else
	{
		tmp1 = ft_strjoin(p + 1, "");
		free((*list)->buf);
		(*list)->buf = tmp1;
	}
}
