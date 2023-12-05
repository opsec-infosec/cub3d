/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 05:13:08 by dfurneau          #+#    #+#             */
/*   Updated: 2021/10/26 20:13:00 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/**
 * Conversion Function Char
 * prints chars to stdout
 **/
void	ft_printf_char(t_printf *t)
{
	unsigned char	c;

	c = va_arg(t->args, int);
	t->len += ft_putchar_fd(c, 1);
	return ;
}
