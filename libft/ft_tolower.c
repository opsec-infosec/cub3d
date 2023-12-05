/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:55:01 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:28:13 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Convert character c to lowercase
 **/
int	ft_tolower(int c)
{
	int	temp;

	temp = c;
	if (c >= 0x41 && c <= 0x5a)
		temp = c + 0x20;
	return (temp);
}
