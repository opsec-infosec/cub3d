/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:02:36 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/20 11:03:15 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Free memory from a char **
 * Such as split
 * Checks for NULLs prior to freeing
 *  SIGABRT Protection
 **/
void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		if (*str)
		{
			while (*(str + i))
				free(*(str + i++));
		}
		free(str);
		str = NULL;
	}
}
