/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 20:21:10 by dfurneau          #+#    #+#             */
/*   Updated: 2021/11/06 16:16:32 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Write a single character to fd
 * Returns the number of characters written
 **/
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, sizeof(c)));
}
