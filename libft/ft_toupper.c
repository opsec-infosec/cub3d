/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:55:01 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:28:25 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Convert character c to uppercase
 **/
int	ft_toupper(int c)
{
	int	temp;

	temp = c;
	if (c >= 0x61 && c <= 0x7a)
		temp = c - 0x20;
	return (temp);
}
