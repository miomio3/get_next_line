#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	count_buf(size_t buff_size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);

#endif