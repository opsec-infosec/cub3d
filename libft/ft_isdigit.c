/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:06:44 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:03:44 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 1 if character is a number
 **/
int	ft_isdigit(int c)
{
	int	pass;

	pass = 0;
	if (c >= 0x30 && c <= 0x39)
		pass = 1;
	return (pass);
}
