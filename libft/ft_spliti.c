/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spliti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:02:11 by dfurneau          #+#    #+#             */
/*   Updated: 2022/04/15 19:02:14 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	a_count(char const *str, char sep, char ignore)
{
	size_t	count;
	size_t	icount;

	count = 1;
	icount = 0;
	while (*str)
	{
		if (*str == sep)
			count = 0;
		while (*str && *str != sep)
		{
			if (*str == ignore)
				icount++;
			str++;
		}
		if (*str && *str == sep)
			while (*str && *str == sep)
				str++;
		if (*str != 0x00 && !(icount % 2))
			count++;
	}
	return (count);
}

static int	s_count(char **str, char sep, char ignore)
{
	size_t	i;
	size_t	icount;

	icount = 0;
	i = 0;
	while ((*str)[i] != 0x00 && ((icount % 2) || (*str)[i] != sep))
	{
		if ((*str)[i] == ignore)
			icount++;
		i++;
	}
	return (i);
}

static char	*copy_string(char **str, char sep, char ignore)
{
	char	*newstr;
	size_t	icount;
	size_t	i;

	newstr = (char *)malloc(sizeof(char) * (s_count(str, sep, ignore) + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	icount = 0;
	while ((**str != sep || icount % 2) && **str != 0x00)
	{
		if (**str == ignore)
			icount++;
		newstr[i++] = *(*str)++;
	}
	newstr[i] = 0x00;
	return (newstr);
}

/**
 * Split the string (*s) by the character (c)
 * Ignores character (c) when between (ignore) character, such as " "
 * Returns an array of the split strings without splitting within ignore
 * FREE REQ
 **/
char	**ft_spliti(char const *s, char c, char ignore)
{
	char	*w;
	char	**out;
	size_t	i;

	if (!s)
		return (NULL);
	out = (char **)malloc(sizeof(char *) * (a_count(s, c, ignore) + 1));
	if (!out)
		return (NULL);
	w = (char *)s;
	i = 0;
	while (*w)
	{
		while (*w == c)
			w++;
		if (*w == 0x00)
			break ;
		out[i] = copy_string(&w, c, ignore);
		if (!out[i])
			return (NULL);
		i++;
	}
	out[i] = NULL;
	return (out);
}
