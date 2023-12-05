/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 08:15:56 by dfurneau          #+#    #+#             */
/*   Updated: 2022/05/21 00:56:43 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 1 if string is a number
 * Number and '+' and '-' at the beginning
 **/
int	ft_strisdigit(char *str)
{
	int	i;
	int	pass;

	i = 0;
	pass = true;
	if (!*str)
		return (false);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			pass = false;
		i++;
	}
	return (pass);
}
