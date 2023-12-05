/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 08:09:44 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:34:29 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/**
 * Printf function
 * Conversions supported: %cspdiuxX
 * Flags: # +0
 * Returns number of characters printed to stdout
 **/
int	ft_printf(const char *format, ...)
{
	t_printf	*table;
	int			len;
	int			i;

	table = (t_printf *)malloc(sizeof(t_printf));
	if (!table)
		return (-1);
	table = ft_init(table);
	table->len = 0;
	va_start(table->args, format);
	i = -1;
	len = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_eval_fmt(format, i + 1, table);
		else
			len += ft_putchar_fd(format[i], 1);
	}
	va_end(table->args);
	len += table->len;
	free (table);
	return (len);
}

/**
 * Called from ft_printf()
 * Parses Flags and puts them in a structure
 **/
int	ft_eval_fmt(const char *f, int p, t_printf *t)
{
	while (f[p] != 'c' && f[p] != 's' && f[p] != 'p' && f[p] != 'd'
		&& f[p] != 'i' && f[p] != 'u' && f[p] != 'x' && f[p] != 'X'
		&& f[p] != '%')
	{
		if (f[p] == '#')
			t->hash = 1;
		if (f[p] == '+')
			t->sign = 1;
		else if (f[p] == ' ' && !t->sign)
			t->sp = 1;
		if (f[p] == '-')
			t->just = ft_atoi(f + p + 1);
		if (f[p] == '0' && t->zero == 0)
			t->zero = ft_atoi(f + (p + 1));
		if (f[p] >= '1' && f[p] <= '9' && t->zero == 0)
			t->width = ft_atoi(f + p);
		p++;
	}
	ft_eval_conv(f, p, t);
	return (p);
}

/**
 * Called from ft_eval_fmt()
 * Parses Conversions and calls the
 * conversion functions to print to stdout
 **/
void	ft_eval_conv(const char *f, int p, t_printf *t)
{
	if (f[p] == 'c')
		ft_printf_char(t);
	if (f[p] == 's')
		ft_printf_str(t);
	if (f[p] == 'd' || f[p] == 'i')
		ft_printf_int(t);
	if (f[p] == 'x')
		ft_printf_hex(t, 0);
	if (f[p] == 'X')
		ft_printf_hex(t, 1);
	if (f[p] == 'u')
		ft_printf_uint(t);
	if (f[p] == 'p')
		ft_printf_ptr(t);
	if (f[p] == '%')
		t->len += ft_putchar_fd('%', 1);
	ft_init(t);
	return ;
}

/**
 * Initialize and Clear the
 * flags table
 **/
t_printf	*ft_init(t_printf *table)
{
	table->hash = 0;
	table->sign = 0;
	table->sp = 0;
	table->zero = 0;
	table->is_neg = 0;
	table->width = 0;
	table->just = 0;
	table->ncount = 0;
	return (table);
}
