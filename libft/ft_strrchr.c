/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 21:20:29 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:26:40 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Search a string (*s) from the end for the occurance of (c)
 * Returns a pointer of the occurance
 **/
char	*ft_strrchr(const char *s, int c)
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
