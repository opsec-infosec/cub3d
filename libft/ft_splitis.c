/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 19:02:11 by dfurneau          #+#    #+#             */
/*   Updated: 2022/05/14 16:26:42 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	i_count(char const c, char *ignore, int icount)
{
	int			i;
	static char	last_seen;

	i = 0;
	if (icount == 0)
		last_seen = 0x00;
	while (ignore[i])
	{
		if (c == ignore[i++])
		{
			if (c == last_seen)
				icount--;
			else if (last_seen == 0x00)
			{
				icount++;
				last_seen = c;
			}
		}
	}
	return (icount);
}

static int	w_count(char const *str, char sep, char *ignore)
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
			icount = i_count(*str, ignore, icount);
			str++;
		}
		if (*str && *str == sep)
			while (*str && *str == sep)
				str++;
		if (*str != 0x00 && icount == 0)
			count++;
	}
	return (count);
}

static int	s_count(char **str, char sep, char *ignore)
{
	size_t	i;
	int		icount;

	icount = 0;
	i = 0;
	while ((*str)[i] != 0x00 && ((*str)[i] != sep || icount != 0))
	{
		icount = i_count((*str)[i], ignore, icount);
		i++;
	}
	return (i);
}

static char	*copy_string(char **str, char sep, char *ignore)
{
	char	*newstr;
	int		len;
	int		i;

	len = s_count(str, sep, ignore) + 1;
	newstr = (char *)malloc(sizeof(char) * (len));
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < len - 1)
		newstr[i++] = *(*str)++;
	newstr[i] = 0x00;
	return (newstr);
}

/**
 * Split the string (*s) by the character (c)
 * Ignores character (c) when between (ignore) string array, such as " "
 * or ' '  or "    '    " and '     "     '
 * Returns an array of the split strings without splitting within ignore
 * FREE REQ
 **/
char	**ft_splitis(char const *s, char c, char *ignore)
{
	char	*w;
	char	**out;
	size_t	i;

	if (!s || !ignore)
		return (NULL);
	out = (char **)malloc(sizeof(char *) * (w_count(s, c, ignore) + 1));
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
