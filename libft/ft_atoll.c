/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:41:30 by dfurneau          #+#    #+#             */
/*   Updated: 2022/04/21 01:52:05 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Convert ASCII to Long Long
 * Returns  long long
 **/
long long	ft_atoll(const char *str)
{
	int			neg;
	long long	result;
	int			count;

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
		return (result * (long long)neg);
}
