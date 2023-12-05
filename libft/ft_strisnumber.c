/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 08:15:56 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/21 17:40:49 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 1 if string is a number
 * Number and '+' and '-' is not included
 * and will return false
 **/
int	ft_strisnumber(char *str)
{
	int	i;
	int	pass;

	i = 0;
	pass = true;
	if (!*str)
		return (false);
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			pass = false;
		i++;
	}
	return (pass);
}
