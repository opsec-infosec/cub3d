/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:36:30 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:17:22 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Writes a integer number to fd
 * Returns the number of ints written to fd
 **/
int	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	len;

	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len += ft_putchar_fd(0x2d, fd);
	}
	if (n > 9)
	{
		i = 1;
		while (n / i >= 10)
			i *= 10;
		while (i >= 1)
		{
			len += ft_putchar_fd((n / i % 10 + 0x30), fd);
			i /= 10;
		}
	}
	else
		len += ft_putchar_fd((n + 0x30), fd);
	return (len);
}
