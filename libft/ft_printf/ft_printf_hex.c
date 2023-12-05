/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:58:35 by dfurneau          #+#    #+#             */
/*   Updated: 2021/10/31 12:14:18 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/**
 * Conversion Function Hexadecimal
 * Decimal to Hexadecimal based on
 * the value of ucse uppercase / lowercase
 **/
void	ft_printf_hex(t_printf *t, int ucse)
{
	unsigned int		d;
	int					pad;
	char				*str;
	char				*hash;

	if (ucse)
	{
		str = "0123456789ABCDEF";
		hash = "0X";
	}
	else
	{
		str = "0123456789abcdef";
		hash = "0x";
	}
	d = va_arg(t->args, unsigned int);
	ft_unum_count(d, 16, t);
	if (t->hash && d != 0)
		t->len += ft_putstr_fd(hash, 1);
	pad = (t->zero) - (t->sign + t->sp + t->is_neg + t->ncount + (t->hash * 2));
	t->len += ft_pad(pad);
	if (d == 0)
		t->len += ft_putchar_fd('0', 1);
	else
		t->len += puthex(d, str, str[0]);
}
