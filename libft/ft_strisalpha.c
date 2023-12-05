/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 08:34:32 by dfurneau          #+#    #+#             */
/*   Updated: 2022/05/21 00:57:42 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Returns 1 if string is an alpha
 * A to Z and a to z
 **/
int	ft_strisalpha(char *str)
{
	int	i;
	int	pass;

	i = 0;
	pass = true;
	if (!*str)
		return (false);
	while (str[i])
	{
		if (!(ft_isalpha(str[i])))
			pass = false;
		i++;
	}
	return (pass);
}
