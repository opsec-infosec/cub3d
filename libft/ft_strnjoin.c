/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 06:52:21 by dfurneau          #+#    #+#             */
/*   Updated: 2022/04/30 08:26:59 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Join N strings together
 * n = Number of strings
 * ... = Strings to join
 * Returns the concatenated string
 * FREE REQ
 **/
char	*ft_strnjoin(size_t n, ...)
{
	va_list	svl;
	char	*tmp;
	char	*s1;
	char	*s2;
	char	*s3;

	if (n <= 1)
		return (NULL);
	va_start(svl, n);
	s1 = va_arg(svl, char *);
	s2 = va_arg(svl, char *);
	s3 = ft_strjoin(s1, s2);
	n -= 2;
	while (n-- > 0)
	{
		tmp = ft_strjoin(s3, va_arg(svl, char *));
		free(s3);
		s3 = NULL;
		if (!tmp)
			break ;
		s3 = ft_strdup(tmp);
		free(tmp);
	}
	va_end(svl);
	return (s3);
}
