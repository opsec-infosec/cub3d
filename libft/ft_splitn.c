/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:28:38 by hawadh            #+#    #+#             */
/*   Updated: 2022/05/31 23:56:46 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	the_splitn(char **out, char *s, char c, int n)
{
	int	i;
	int	j;

	i = 0;
	while (*s)
	{
		j = 0;
		while (*s && *s == c && n > 0)
		{
			s++;
			n--;
		}
		while (*s && (*s != c || n <= 0))
			out[i][j++] = *s++;
		i++;
	}
	out[i] = NULL;
}

static void	memory_alloc(char **out, char *s, char c, int n)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	while (s[j])
	{
		count = 0;
		while (s[j] && s[j] == c && n > 0)
		{
			n--;
			j++;
		}
		while (s[j] && (s[j] != c || n <= 0))
		{
			count++;
			j++;
		}
		if (count >= 1)
			out[i] = (char *)ft_calloc((count + 1), sizeof(char));
		i++;
	}
}

static int	delim_counter(char *s, char c, int n)
{
	int		i;
	int		delim;

	i = 0;
	delim = 0;
	n += 1;
	while (s[i] && n > 0)
	{
		if (s[i] == c)
		{
			i++;
			n--;
		}
		else
		{
			delim++;
			n--;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (delim);
}

/**
*	Function splits a string up to n delimiter.
**	n <= 0		Function returns NULL
**	FREE REQ
**/
char	**ft_splitn(char const *s, char c, size_t n)
{
	char	**out;
	int		delim;

	if (n <= 0)
		return (NULL);
	if (!s)
		return (ft_calloc(1, 1));
	delim = delim_counter((char *)s, c, n);
	out = (char **)ft_calloc((delim + 2), sizeof(char *));
	if (!out)
		return (NULL);
	memory_alloc(out, (char *)s, c, n);
	the_splitn(out, (char *)s, c, n);
	return (out);
}
