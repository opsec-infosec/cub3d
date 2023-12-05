/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 22:21:57 by dfurneau          #+#    #+#             */
/*   Updated: 2022/04/22 23:13:26 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compare s2 and s1
 * Returns the difference between the strings
 **/
int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	while (i >= 0 && j >= 0)
	{
		if (s1[i] != s2[j])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[j]);
		i--;
		j--;
	}
	if (i >= 0)
		return (((unsigned char *)s1)[i] - 0x00);
	if (j >= 0)
		return (0x00 - ((unsigned char *)s2)[j]);
	return (0);
}
