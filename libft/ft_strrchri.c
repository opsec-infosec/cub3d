/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:20:29 by dfurneau          #+#    #+#             */
/*   Updated: 2022/06/05 12:11:50 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	i_count(char const c, const char *ignore, int icount)
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

/**
 * Search a string (*s) from the end for the occurance of (c)
 * Ignore when inside string (ignore)
 * Returns a pointer of the occurance
 **/
char	*ft_strrchri(const char *s, int c, const char *ignore)
{
	size_t	i;
	int		ignore_cnt;

	i = 1;
	ignore_cnt = 0;
	while (*s)
	{
		s++;
		i++;
	}
	while (i > 0)
	{
		ignore_cnt = i_count(*s, ignore, ignore_cnt);
		if (*s == (char)c && !ignore_cnt)
			return ((char *)s);
		i--;
		s--;
	}
	return (NULL);
}
