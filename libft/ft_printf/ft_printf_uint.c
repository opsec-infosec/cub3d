/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:53:21 by dfurneau          #+#    #+#             */
/*   Updated: 2021/10/27 20:18:59 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/**
 * Conversion Function Unsigned Int
 * Decimal to unsigned int
 **/
void	ft_printf_uint(t_printf *t)
{
	unsigned int	d;
	int				pad;

	d = va_arg(t->args, unsigned int);
	ft_unum_count(d, 10, t);
	if (t->sp)
		t->len += ft_putchar_fd(0x20, 1);
	pad = (t->zero) - ((t->sign) + (t->sp) + (t->is_neg) + t->ncount);
	t->len += ft_pad(pad);
	t->len += ft_putunbr_fd(d, 1);
	return ;
}
