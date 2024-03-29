/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfurneau <dfurneau@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:44:47 by dfurneau          #+#    #+#             */
/*   Updated: 2022/12/21 17:34:12 by dfurneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

typedef unsigned long long	t_uint_ll;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

typedef enum e_bool
{
	false,
	true
}t_bool;

typedef struct s_vector
{
	double	xd;
	double	yd;
	int		xi;
	int		yi;
}	t_vector;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isalnum(int c);
int			ft_ispunctuation(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_strisdigit(char *str);
int			ft_strisnumber(char *str);
int			ft_strisalpha(char *str);
int			ft_strisalnum(char *str);
int			ft_strisascii(char *str);
int			ft_strisprint(char *str);
int			ft_strispunctuation(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *str);
size_t		ft_ptrptrlen(char **ptr);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strchr(const char *s, int c);
char		*ft_strchri(const char *s, int c, const char *i);
char		*ft_strrchr(const char *s, int c);
char		*ft_strrchri(const char *s, int c, const char *ignore);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strnjoin(size_t n, ...);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strrmc(char *s1, char c);
char		*ft_strrmstr(char *s1, char *set);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
char		**ft_splitn(char const *s, char c, size_t n);
char		**ft_spliti(char const *s, char c, char ignore);
char		**ft_splitis(char const *s, char c, char *ignore);
int			ft_abs(int nbr);
int			ft_isneg(int nbr);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
double		ft_atof(const char *str);
long long	ft_atoll(const char *str);
t_uint_ll	ft_atoull(const char *str);
char		*ft_itoa(int n);
char		*ft_dtoa(double nbr, unsigned int decimals);
void		*ft_realloc(void *ptr, size_t originalsize, size_t newsize);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_free_split(char **str);
int			ft_putchar_fd(char c, int fd);
int			ft_putstr_fd(char *s, int fd);
int			ft_putendl_fd(char *s, int fd);
int			ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			ft_puthex(unsigned int n, int ucse);
void		ft_swapi(int *a, int *b);
void		ft_swap(void **a, void **b);

#endif
