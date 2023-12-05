/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:01:55 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:07:21 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Iterate through the list and apply the 
 * function to the element content var
 **/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cur;

	if (lst)
	{
		cur = lst;
		while (cur)
		{
			f(cur->content);
			cur = cur->next;
		}
	}
}
