/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:03:52 by dfurneau          #+#    #+#             */
/*   Updated: 2022/05/21 00:58:43 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 1 if string is printable
 **/
int	ft_strisprint(char *str)
{
	int	i;
	int	pass;

	i = 0;
	pass = true;
	while (str[i])
	{
		if (!(ft_isprint(str[i])))
			pass = false;
		i++;
	}
	return (pass);
}
