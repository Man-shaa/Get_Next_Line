#include "get_next_line.h"

char	ft_line(char *new_line, char **line, char *str)
{
	*line = ft_substr(str, 0, ft_strlen(str) - ft_strlen(new_line));
	str = ft_substr(str, ft_strlen(*line), ft_strlen(str));
	return (1);
}

char	ft_end(char **line, char *str)
{
	if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			n;
	char		buffer[BUFFER_SIZE + 1];
	static char	*str;
	char		*temp;
	char		*new_line;

	n = BUFFER_SIZE;
	if ((new_line = ft_strrchr(str)))
		return(ft_line(new_line, line, str));
	while ((n = read(fd, buffer, BUFFER_SIZE) > 0))
	{
		buffer[n] = '\0';
		if (n == 0)
			break ;
		temp = ft_strjoin(str, buffer);
		str = temp;
		if((new_line = ft_strrchr(buffer)))
			return(ft_line(new_line, line, str));
	}
	if (n == -1)
		return (-1);
	return (ft_end(line, str));
}