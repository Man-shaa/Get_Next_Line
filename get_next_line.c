/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:19:54 by msharifi          #+#    #+#             */
/*   Updated: 2022/05/19 19:12:14 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*is_remaining(char *str, char *buffer)
{
	if (!str || str[0] == '\0')
		return (NULL);
	buffer = ft_strjoin(buffer, str);
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	*get_line(char *str, char *buffer, char *line, int fd)
{
	int		byte;
	int		i;

	i = 0;
	byte = 1;
	while (ft_strchr(str) == -1 && byte != 0)
	{
		byte = read(fd, str, BUFFER_SIZE);
		if (byte < 0 || str[0] == '\0')
			return (NULL);
		if (byte <= 0)
			return (buffer);
		str[BUFFER_SIZE + 1] = '\0';
		buffer = ft_strjoin(buffer, str);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		line = ft_substr(buffer, 0, ft_strchr(buffer) + 1);
		return (free(buffer), line);
	}
	return (buffer);
}

char	*get_remaining(char *str)
{
	int		i;
	int		j;
	char	*remaining;

	i = 0;
	j = 0;
	remaining = NULL;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (NULL);
	remaining = ft_calloc(ft_strlen(str) - i, 1);
	i++;
	while (str[i])
		remaining[j++] = str[i++];
	remaining[j] = '\0';
	ft_strcpy(str, remaining);
	return (free(remaining), str);
}

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1] = {0};
	char		*buffer;
	char		*line;

	buffer = NULL;
	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1023)
		return (NULL);
	buffer = is_remaining(str, buffer);
	line = get_line(str, buffer, line, fd);
	if (!line)
		return (NULL);
	get_remaining(str);
	return (line);
}
