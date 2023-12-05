/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:22:43 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:05:41 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Add a Structure Element to the end of the list
 **/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		(ft_lstlast(*lst))->next = new;
	}
}
