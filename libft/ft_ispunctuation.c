/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunctuation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:50:27 by dfurneau          #+#    #+#             */
/*   Updated: 2022/05/21 00:59:12 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 ** Returns 1 if char an Punctuation
 ** !@#%^&*-+[]{},.?~:;
 **/
int	ft_ispunctuation(int c)
{
	static char	*symb = {"!@#%^&*-+[]{},.?~:;"};
	int			pass;
	int			i;

	pass = false;
	i = 0;
	while (symb[i])
	{
		if (c == symb[i++])
			pass = true;
	}
	return (pass);
}
