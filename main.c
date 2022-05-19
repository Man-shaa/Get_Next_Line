#include "get_next_line.h"
#include <stdio.h>
    #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

int	main(int ac, char **av)
{
	(void)ac;
	char	*line;
	int	fd = open(av[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	close(fd);
	return (0);
}
