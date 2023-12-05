/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:35:10 by dfurneau          #+#    #+#             */
/*   Updated: 2021/10/31 13:38:21 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

char			*get_next_line(int fd);
char			*free_blk(char *str, size_t s);
size_t			gnl_strlennl(const char *str);
char			*gnl_strjoin(char *s1, char *s2, size_t s2s);
char			*gnl_strrchr(char *s, int c);

#endif
