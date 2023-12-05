/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:02:58 by dfurneau          #+#    #+#             */
/*   Updated: 2022/05/03 13:34:36 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Re Allocate Memory
 * *ptr = Original allocated memory of ptr
 * originalsize = Original Size of allocated memory of *ptr
 * newsize = New size of memory needed for ptr
 * Returns new memory allocation
 * if ptr = NULL, then returns new allocation of memory of newsize
 * if newsize = 0, frees original ptr if not NULL
 * FREE REQ
 **/
void	*ft_realloc(void *ptr, size_t originalsize, size_t newsize)
{
	void	*p;

	if (!ptr)
	{
		p = malloc(newsize);
		if (!p)
			p = NULL;
	}
	else if (ptr && newsize == 0)
	{
		free(ptr);
		p = NULL;
	}
	else
	{
		p = malloc(newsize);
		if (!p)
			return (NULL);
		if (newsize >= originalsize)
			p = ft_memcpy(p, ptr, originalsize);
		else
			p = ft_memcpy(p, ptr, newsize);
		free(ptr);
	}
	return (p);
}
