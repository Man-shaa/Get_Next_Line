#ifndef GETNEXTLINE_H
# define GETNEXTLINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int	    ft_strlen(char *str);
char	*ft_strrchr(char *str);
char	*ft_strjoin(char *s1 , char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);

char	ft_line(char *new_line, char **line, char *str);
char	ft_end(char **line, char *str);
int     get_next_line(int fd, char **line);

#endif