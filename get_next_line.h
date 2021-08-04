#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct l_list
{
	struct l_list	*next;
	int				fd;
	char			*buf;
}t_list;

char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t n, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		*ft_memset(void *buf, int ch, size_t n);
int			create_line(char **line, char *buf);
char		*ft_strdup(const char *src);

#endif