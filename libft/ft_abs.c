/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:13:22 by dfurneau          #+#    #+#             */
/*   Updated: 2022/01/03 19:11:53 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Convert Integer Number
 * to Absolute Value
 **/
int	ft_abs(int nbr)
{
	if (ft_isneg(nbr))
		return (nbr * -1);
	else
		return (nbr);
}
