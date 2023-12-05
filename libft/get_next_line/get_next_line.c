/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:37:22 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:32:44 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(char **buffer, char **str, int fd)
{
	ssize_t	rb;

	rb = 1;
	while (rb != 0 && (!gnl_strrchr(*str, 0x0a)))
	{
		rb = read(fd, *buffer, BUFFER_SIZE);
		if (rb == -1)
		{
			free (*buffer);
			free(*str);
			return (NULL);
		}
		if (rb != 0)
			*str = gnl_strjoin(*str, *buffer, rb);
	}
	free(*buffer);
	return (*str);
}

static char	*get_buffer(int fd, char *str)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!str)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = 0x00;
	}
	return (read_buffer(&buffer, &str, fd));
}

static char	*get_line(char **str)
{
	char	*newline;
	size_t	i;

	if (!(*str))
		return (NULL);
	newline = (char *)malloc(sizeof(char) * (gnl_strlennl(*str) + 1));
	if (!newline)
		return (NULL);
	i = 0;
	while ((*str)[i] != 0x00 && (*str)[i] != 0x0a)
	{
		newline[i] = (*str)[i];
		i++;
	}
	if ((*str)[i] == 0x0a)
	{
		newline[i] = (*str)[i];
		newline[++i] = 0x00;
	}
	else if ((*str)[i] == 0x00)
		newline[i] = (*str)[i];
	*str = free_blk(*str, i);
	return (newline);
}

/**
 * Pass the open file (fd)
 * Returns the current line up to newline
 * Subsquent calls returns the next line up to newline
 * FREE REQ
 **/
char	*get_next_line(int fd)
{
	static char	*s[1024];
	char		*cline;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	s[fd] = get_buffer(fd, s[fd]);
	cline = get_line(&s[fd]);
	if (!cline)
	{
		free(s[fd]);
		s[fd] = NULL;
		return (NULL);
	}
	if (!*cline)
	{
		free(s[fd]);
		s[fd] = NULL;
		free(cline);
		return (NULL);
	}
	return (cline);
}
