/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:18:45 by msharifi          #+#    #+#             */
/*   Updated: 2022/05/13 15:44:17 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str && *str != c)
		str++;
	if (*str == c)
		return ((char *)str);
	return (NULL);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	i = 0;
// 	j = 0;
// 	if (!s1)
// 	{
// 		s1 = malloc(sizeof(char) * 1);
// 		s1[0] = '\0';
// 	}
// 	if (!s2)
// 		return (NULL);
// 	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
// 	while (s1[i])
// 	{
// 		i++;
// 		str[i] = s1[i];
// 	}
// 	while (s2[j])
// 		str[i++] = s2[j++];
// 	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
// 	free(s1);
// 	return (str);
// }

char	*ft_strjoin(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = -1;
	j = 0;
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!buff)
		return (NULL);
	s = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buff) + 1));
	if (s == NULL)
		return (NULL);
	if (str)
		while (str[++i] != '\0')
			s[i] = str[i];
	while (buff[j] != '\0')
		s[i++] = buff[j++];
	s[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free(str);
	return (s);
}