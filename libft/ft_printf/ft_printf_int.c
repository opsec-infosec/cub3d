/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 05:12:25 by dfurneau          #+#    #+#             */
/*   Updated: 2021/10/27 20:18:06 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/**
 * Conversion Function Signed Int
 * Decimal to signed int
 **/
void	ft_printf_int(t_printf *t)
{
	int	d;
	int	pad;

	d = va_arg(t->args, int);
	ft_snum_count(d, 10, t);
	if ((t->sign || t->sp) && d >= 0)
	{
		if (t->sign)
			t->len += ft_putchar_fd(0x2b, 1);
		if (t->sp)
			t->len += ft_putchar_fd(0x20, 1);
	}
	if (t->is_neg)
		t->len += ft_putchar_fd(0x2d, 1);
	pad = (t->zero) - ((t->sign) + (t->sp) + (t->is_neg) + t->ncount);
	t->len += ft_pad(pad);
	t->len += ft_putsnbr_fd(d, 1);
	return ;
}
