/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:56:31 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:22:40 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Concatenate string src and dest up to size dstsize
 * Returns the total size of the concatenated string
 **/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	i;

	len_dst = 0;
	i = 0;
	while (dst[len_dst] && len_dst < dstsize)
		len_dst++;
	while (src[i] && (len_dst + i + 1) < dstsize)
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	if (len_dst < dstsize)
		dst[len_dst + i] = 0x00;
	return (len_dst + ft_strlen(src));
}
