/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:19:50 by msharifi          #+#    #+#             */
/*   Updated: 2022/05/12 21:45:03 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>

size_t	ft_strlen(char *str);
void	ft_bzero(void *ptr, size_t len);
char	*ft_strchr(char *str, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);

char	*get_buffer(char *str, int fd);
char	*get_line(char *str);
char	*remainding_line(char *str);
char	*get_next_line(int fd);

#endif