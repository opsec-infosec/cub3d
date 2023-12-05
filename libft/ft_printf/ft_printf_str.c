/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 05:12:50 by dfurneau          #+#    #+#             */
/*   Updated: 2021/10/27 20:19:06 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/**
 * Conversion Function Sttring
 * Prints strings to stdout
 **/
void	ft_printf_str(t_printf *t)
{
	char	*str;
	int		pad;

	str = va_arg(t->args, char *);
	if (!str)
	{
		t->len += ft_putstr_fd("(null)", 1);
		return ;
	}
	pad = (t->zero - ft_strlen(str));
	t->len += ft_pad(pad);
	t->len += ft_putstr_fd(str, 1);
	return ;
}
