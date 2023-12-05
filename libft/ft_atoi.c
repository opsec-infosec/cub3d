/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:41:30 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:04:34 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Convert ASCII to Integer
 * Returns the integer
 **/
int	ft_atoi(const char *str)
{
	int	neg;
	int	result;
	int	count;

	neg = 1;
	count = 0;
	result = 0;
	while ((*str && *str == 0x20) || (*str >= 7 && *str <= 13))
		str++;
	while (*str == 0x2d || *str == 0x2b)
	{
		if (*str++ == 0x2d)
			neg *= -1;
		count++;
	}
	while (*str >= 0x30 && *str <= 0x39)
		result = result * 10 + *str++ - 0x30;
	if (count > 1)
		return (0);
	else
		return (result * neg);
}
