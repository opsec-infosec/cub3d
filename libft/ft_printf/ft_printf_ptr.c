/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:58:35 by dfurneau          #+#    #+#             */
/*   Updated: 2021/10/31 12:15:02 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/**
 * Conversion Function Pointer
 * Uses the hexadecimal conversion
 **/
void	ft_printf_ptr(t_printf *t)
{
	unsigned long	d;
	char			*str;

	str = "0123456789abcdef";
	d = va_arg(t->args, unsigned long);
	t->len += ft_putstr_fd("0x", 1);
	if (d == 0)
		t->len += ft_putnbr_fd(d, 1);
	else
		t->len += puthex(d, str, str[0]);
	return ;
}
