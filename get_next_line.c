/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:19:54 by msharifi          #+#    #+#             */
/*   Updated: 2022/05/13 19:12:35 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_buffer(char *str, int fd)
{
	char	*buffer;
	int		byte;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte = 1;
	while (ft_strchr(str, '\n') == NULL && byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[byte] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	while (str[j] && str[j] != '\n')
	{
		line[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*remainding_line(char *str)
{
	char	*remainding;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	remainding = malloc(ft_strlen(str) - i + 1);
	if (!remainding)
		return (NULL);
	i++;
	while (str[i])
		remainding[j++] = str[i++];
	remainding[j] = '\0';
	free(str);
	return (remainding);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1023)
		return (NULL);
	str = get_buffer(str, fd);
	if (!str)
		return (NULL);
	line = get_line(str);
	if (!line)
		return (NULL);
	str = remainding_line(str);
	return (line);
}
