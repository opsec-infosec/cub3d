/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:25:31 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:23:40 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Calculate the length of a stirng
 * Returns length
 **/
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str++) != 0x00)
		i++;
	return (i);
}
