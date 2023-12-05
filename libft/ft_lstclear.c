/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:35:00 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:06:21 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Clears the entire list of elements
 **/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*nxt;

	if (lst)
	{
		cur = *lst;
		while (cur)
		{
			nxt = cur->next;
			ft_lstdelone(cur, del);
			cur = nxt;
		}
		*lst = NULL;
	}
}
