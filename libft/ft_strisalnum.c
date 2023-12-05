/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:01:16 by dfurneau          #+#    #+#             */
/*   Updated: 2022/05/21 00:58:12 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 1 if string is an alphanumeric
 * A to Z and a to z or 0 to 9
 **/
int	ft_strisalnum(char *str)
{
	int	i;
	int	pass;

	i = 0;
	pass = true;
	if (!*str)
		return (false);
	while (str[i])
	{
		if (!(ft_isalnum(str[i])))
			pass = false;
		i++;
	}
	return (pass);
}
