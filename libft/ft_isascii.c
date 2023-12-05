/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:35:25 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:03:20 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 1 if char is ASCII
 **/
int	ft_isascii(int c)
{
	int	pass;

	pass = 0;
	if (c >= 0 && c <= 127)
		pass = 1;
	return (pass);
}
