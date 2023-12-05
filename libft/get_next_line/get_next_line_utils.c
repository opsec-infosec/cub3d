/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:37:44 by dfurneau          #+#    #+#             */
/*   Updated: 2021/10/31 13:27:02 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++ != 0x00)
		i++;
	return (i);
}

size_t	gnl_strlennl(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != 0x00 && *str != 0x0a)
	{
		i++;
		str++;
	}
	if (*str == 0x0a)
		i++;
	return (i);
}

char	*free_blk(char *str, size_t s)
{
	size_t	i;
	char	*newline;

	newline = (char *)malloc(sizeof(char) * (gnl_strlen(str + s) + 1));
	if (!newline)
		return (NULL);
	i = 0;
	while (str[i + s] != 0x00)
	{
		newline[i] = str[i + s];
		i++;
	}
	newline[i] = 0x00;
	free(str);
	if (i == 0)
	{
		free(newline);
		return (NULL);
	}
	return (newline);
}

char	*gnl_strjoin(char *s1, char *s2, size_t s2s)
{
	char	*cats;
	size_t	i;
	size_t	s1s;

	if (!(s1 && s2))
		return (NULL);
	s1s = gnl_strlennl(s1);
	cats = (char *)malloc(sizeof(*cats) * (s1s + s2s + 1));
	if (!cats)
		return (NULL);
	i = 0;
	while (i < s1s)
	{
		cats[i] = s1[i];
		i++;
	}
	while (i < (s2s + s1s))
	{
		cats[i] = s2[i - s1s];
		i++;
	}
	free(s1);
	cats[i] = 0x00;
	return (cats);
}

char	*gnl_strrchr(char *s, int c)
{
	size_t	i;

	i = 1;
	while (*s)
	{
		s++;
		i++;
	}
	while (i > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		i--;
		s--;
	}
	return (NULL);
}
