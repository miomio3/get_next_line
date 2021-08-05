#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct l_list
{
	struct l_list	*next;
	int				fd;
	char			*buf;
}t_list;

char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
void		*ft_calloc(size_t n, size_t size);
char		*listbuf_join(t_list **list);
t_list		*front_list(t_list **list);
int			free_list(t_list **list);
int			create_list(t_list **list, int fd);
char		*ft_substr(char const *s, char *p);

#endif