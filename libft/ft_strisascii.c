/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:02:43 by dfurneau          #+#    #+#             */
/*   Updated: 2022/05/21 00:58:30 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 1 if string is an ascii
 **/
int	ft_strisascii(char *str)
{
	int	i;
	int	pass;

	i = 0;
	pass = true;
	while (str[i])
	{
		if (!(ft_isascii(str[i])))
			pass = false;
		i++;
	}
	return (pass);
}
