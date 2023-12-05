/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:40:41 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:25:59 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Search string (haystack) for the contents of needle up to len
 * returns a pointer to the location of the contents
 **/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	if (*needle == 0x00 || (len == 1 && haystack[0] == needle[0]))
		return ((char *)haystack);
	if (len == 0)
		return (0);
	i = 0;
	j = 0;
	while (haystack[i] && (i < (len - 1) && j < (len - 1)))
	{
		j = 0;
		while ((haystack[j + i] == needle[j]) && j <= (len - 1))
			if (needle[++j] == 0x00)
				return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
