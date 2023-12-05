/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:45:42 by dfurneau          #+#    #+#             */
/*   Updated: 2021/10/26 21:50:40 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/**
 * This Function converts unsigned int to 
 * ascii and prints to the stdout
 **/
int	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned long int	i;
	int					len;

	len = 0;
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

int	ft_putsnbr_fd(int n, int fd)
{
	long int	i;
	int			len;

	len = 0;
	if (n == -2147483648)
		return (write(fd, "2147483648", 10));
	if (n < 0)
		n = n * -1;
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
