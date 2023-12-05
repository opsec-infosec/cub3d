/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:18:35 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:13:57 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Move memory contents from one location to another
 **/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	pdst = (unsigned char *)dst;
	psrc = (const unsigned char *)src;
	if (!(pdst || psrc))
		return (NULL);
	if (pdst > psrc)
	{
		while (len-- > 0)
			*(pdst + len) = *(psrc + len);
	}
	else
	{
		while (len > 0)
		{
			*pdst++ = *psrc++;
			len--;
		}
	}
	return (dst);
}
