/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 20:37:41 by dfurneau          #+#    #+#             */
/*   Updated: 2022/06/05 12:24:38 by dfurneau         ###   ########.fr       */
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
 * Search a string (*s) from the start for the occurance of (c)
 * Ignoring when inside (ignore)
 * Returns a pointer of the occurance
 **/
char	*ft_strchri(const char *s, int c, const char *ignore)
{
	int	ignore_cnt;

	ignore_cnt = 0;
	while (*s)
	{
		ignore_cnt = i_count(*s, ignore, ignore_cnt);
		if (*s == (char)c && !ignore_cnt)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c && !ignore_cnt)
		return ((char *)s);
	return (NULL);
}
