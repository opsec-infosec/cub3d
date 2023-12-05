/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:13:48 by dfurneau          #+#    #+#             */
/*   Updated: 2022/04/30 07:55:34 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Join strings *s1 and *s2 together
 * Returns the concatenated string
 * FREE REQ
 **/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cats;
	int		i;
	int		s1s;
	int		s2s;

	if (!(s1 && s2))
		return (NULL);
	s1s = ft_strlen(s1);
	s2s = ft_strlen(s2);
	cats = (char *)malloc(sizeof(*cats) * (s1s + s2s + 1));
	if (!cats)
		return (NULL);
	i = 0;
	while (i < s1s)
	{
		cats[i] = s1[i];
		i++;
	}
	while (i < (s2s + s1s))
	{
		cats[i] = s2[i - s1s];
		i++;
	}
	cats[i] = 0x00;
	return (cats);
}
