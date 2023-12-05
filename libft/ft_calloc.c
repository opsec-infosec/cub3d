/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:35:16 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:28:48 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Malloc count x size and
 * zero the memory
 * FREE REQ
 **/
void	*ft_calloc(size_t count, size_t size)
{
	void	*mem_ptr;

	mem_ptr = malloc(count * size);
	if (!mem_ptr)
		return (NULL);
	ft_bzero(mem_ptr, (count * size));
	return (mem_ptr);
}
