/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 14:43:00 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:16:23 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 1 if Character is printable
 **/
int	ft_isprint(int c)
{
	int	pass;

	pass = 0;
	if (c >= 32 && c < 127)
		pass = 1;
	return (pass);
}
