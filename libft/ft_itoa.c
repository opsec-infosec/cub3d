/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:44:07 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:29:07 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  Return number of chars in number
 **/
static long	sizeofnbr(long n)
{
	long			i;
	unsigned int	size;

	i = 1;
	size = 1;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n / i >= 10)
	{
		i *= 10;
		size++;
	}
	return (size);
}

/**
 * Calculates the tens, hunderds, thousnads...
 **/
static void	number(long n, char *str, int *i)
{
	if (n > 9)
	{
		number(n / 10, str, i);
		number(n % 10, str, i);
	}
	else
		str[(*i)++] = n + 0x30;
}

/**
 * Convert Integer to ASCII
 * Returns the ASCII char
 * FREE REQ
 **/
char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nbr;

	nbr = n;
	str = (char *)malloc(sizeof(*str) * (sizeofnbr(nbr) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		str[i++] = 0x2d;
		nbr *= -1;
	}
	number(nbr, str, &i);
	str[i] = 0x00;
	return (str);
}
