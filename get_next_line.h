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

typedef struct s_list
{
	struct s_list	*next;
	int				fd;
	char			*buf;
}t_list;

char		*get_next_line(int fd);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*listbuf_join(t_list **list, int f);
char		*free_list(t_list **list);
int			create_list(t_list **tmp, int fd);
char		*ft_substr(char const *s, const char *s1);
void		join_free(t_list **list, char **line, char **tmp2, char *p);

#endif