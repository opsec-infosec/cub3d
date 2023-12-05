/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:19:12 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:02:56 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 1 if char an ASCII
 * from A to Z  or a to z and 0 to 9
 **/
int	ft_isalnum(int c)
{
	int	pass;

	pass = 0;
	if ((c >= 0x41 && c <= 0x5a) || (c >= 0x61 && c <= 0x7a)
		|| (c >= 0x30 && c <= 0x39))
		pass = 1;
	return (pass);
}
