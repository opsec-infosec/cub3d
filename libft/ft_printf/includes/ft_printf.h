/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 08:06:53 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/15 14:27:36 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "../../libft.h"

/**
 * FLAGS STRUCTURE
 **/
typedef struct s_printf
{
	va_list	args;
	int		hash;
	int		sign;
	int		sp;
	int		zero;
	int		is_neg;
	int		width;
	int		just;
	int		ncount;
	int		len;
}	t_printf;

/**
 * PROTOTYPES
 **/
int			ft_printf(const char *format, ...);
int			ft_eval_fmt(const char *f, int p, t_printf *t);
void		ft_eval_conv(const char *f, int p, t_printf *t);
void		ft_printf_char(t_printf *t);
void		ft_printf_str(t_printf *t);
void		ft_printf_int(t_printf *t);
void		ft_printf_uint(t_printf *t);
void		ft_printf_hex(t_printf *t, int ucse);
void		ft_printf_ptr(t_printf *t);
t_printf	*ft_init(t_printf *table);
int			ft_putunbr_fd(unsigned int n, int fd);
int			ft_putsnbr_fd(int n, int fd);
int			puthex(unsigned long n, char *str, char c);
void		ft_snum_count(signed long int n, int base, t_printf *t);
void		ft_unum_count(unsigned long int n, int base, t_printf *t);
int			ft_pad(int count);
int			ft_zero(t_printf *tab, const char *str);

#endif
