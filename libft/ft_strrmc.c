/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrmc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 08:42:11 by dfurneau          #+#    #+#             */
/*   Updated: 2022/05/09 20:18:35 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Remove character c from string s1
 * FREE REQ
 **/

char	*ft_strrmc(char *s1, char c)
{
	char	*tmp;
	int		i;

	tmp = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (*s1)
	{
		if (*s1 != c)
			tmp[i++] = *s1;
		s1++;
	}
	return (tmp);
}
