/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:58:26 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/15 13:37:27 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function converts decimal numbers to hex
 * pass in the hex array 0..F
 **/
static int	ft_convert(unsigned long n, char *str, char c, int base)
{
	int	len;

	len = 0;
	if (n > 0)
	{
		c = (str[n % base]);
		n /= base;
		len = ft_convert(n, str, c, base);
		len += ft_putchar_fd(c, 1);
	}
	return (len);
}

/**
 * ft_puthex takes a unsigned int and case
 * where ucse = 1 for Uppercase and 0 for lowercase
 * Returns the number of characters written to stdio
 **/
int	ft_puthex(unsigned int n, int ucse)
{
	char				*str;

	if (n == 0)
		return (ft_putchar_fd(0, 1));
	if (ucse)
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	return (ft_convert(n, str, str[0], 16));
}

int	ft_putnumber(unsigned int n)
{
	char	*str;

	if (n == 0)
		return (ft_putchar_fd(0, 1));
	str = "0123456789";
	return (ft_convert(n, str, str[0], 10));
}
