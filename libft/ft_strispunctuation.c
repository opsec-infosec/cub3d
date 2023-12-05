/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strispunctuation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 08:34:32 by dfurneau          #+#    #+#             */
/*   Updated: 2022/05/21 00:59:05 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 ** Returns 1 if string is an punctuated
 ** !@#%^&*-+[]{},.?~:;
 **/
int	ft_strispunctuation(char *str)
{
	int	i;
	int	pass;

	i = 0;
	pass = false;
	while (str[i])
	{
		if ((ft_ispunctuation(str[i])))
			pass = true;
		i++;
	}
	return (pass);
}
