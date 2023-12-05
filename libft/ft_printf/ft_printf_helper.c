/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 05:01:10 by dfurneau          #+#    #+#             */
/*   Updated: 2021/10/31 12:13:03 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/**
 * This function converts decimal numbers to hex
 * pass in the hex array 0..F
 **/
int	puthex(unsigned long n, char *str, char c)
{
	int	len;

	len = 0;
	if (n > 0)
	{
		c = (str[n % 16]);
		n /= 16;
		len = puthex(n, str, c);
		len += ft_putchar_fd(c, 1);
	}
	return (len);
}

/**
 * This Function counts the number of digits in
 * an signed number and also determins if the 
 * number is negative
 **/
void	ft_snum_count(signed long int n, int base, t_printf *t)
{
	long int	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
	{
		n *= -1;
		t->is_neg = 1;
	}
	while (n > 0)
	{
		n /= base;
		i++;
	}
	t->ncount = i;
}

/**
 * This Function counts the number of digits in
 * an unsigned number
 **/
void	ft_unum_count(unsigned long int n, int base, t_printf *t)
{
	long int	i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n > 0)
	{
		n /= base;
		i++;
	}
	t->ncount = i;
}

/**
 * This Function pads the output with zeros
 * and prints to stdout
 **/
int	ft_pad(int count)
{
	int	len;

	len = 0;
	if (count < 0)
		return (0);
	while (count > len)
		len += ft_putchar_fd(0x30, 1);
	return (len);
}
