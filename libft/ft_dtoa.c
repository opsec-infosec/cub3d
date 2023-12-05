/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:41:22 by dfurneau          #+#    #+#             */
/*   Updated: 2022/11/23 15:12:22 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

/**
* Convert Double to String up to x decimal points
* Must include math library ie. -lm
* FREE REQ
*/
char	*ft_dtoa(double nbr, unsigned int decimals)
{
	char	*tmp[2];
	char	*ret;
	double	dtmp;

	if (decimals >= INT_MAX)
		return (NULL);
	tmp[0] = ft_itoa((int)nbr);
	tmp[1] = ft_itoa((int)(modf(nbr, &dtmp) * pow(10.0, (double)decimals)));
	ret = ft_strnjoin(3, tmp[0], ".", tmp[1]);
	free(tmp[0]);
	free(tmp[1]);
	return (ret);
}
