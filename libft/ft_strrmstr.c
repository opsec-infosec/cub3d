/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrmstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 08:42:11 by dfurneau          #+#    #+#             */
/*   Updated: 2022/04/18 19:22:33 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Remove character set from string s1
 * FREE REQ
 **/

char	*ft_strrmstr(char *s1, char *set)
{
	char	*tmp;
	char	*ret;
	int		i;

	i = 1;
	ret = ft_strrmc(s1, set[0]);
	while (set[i])
	{
		tmp = ft_strrmc(ret, set[i++]);
		ft_strlcpy(ret, tmp, ft_strlen(tmp) + sizeof(char));
		free(tmp);
	}
	return (ret);
}
