/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ededemog <ededemog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:17:21 by ededemog          #+#    #+#             */
/*   Updated: 2024/07/28 15:21:37 by ededemog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

char			*ft_strrchr(const char *str, int searchedChar);

char			*ft_strchr(const char *str, int searchedChar);

int				ft_atoi(const char *str);

int				ft_tolower(int c);

int				ft_toupper(int c);

int				ft_isdigit(int c);

size_t			ft_sstrlen(const char *str);

void			*ft_memset(void *pointer, int value, size_t count);

void			*ft_memcpy(void *dest, const void *src, size_t size);

void			ft_bzero(void *pointer, size_t count);

//char	*ft_strcpy(char *dest, const char *src);

size_t			ft_strlcpy(char *dst, const char *src, size_t size);

char			*ft_strdup(const char *s);

char			*ft_strcat(char *dest, char *src);

char			*ft_strstr(char *haystack, char *needle);

int				ft_putchar_fd(int c, int fd);

int				ft_putstr_fd(char *str, int fd);

void			ft_putendl_fd(char *str, int fd);

void			*ft_memmove(void *dest, const void *src, size_t len);

void			*ft_calloc(size_t count, size_t size);

char			*ft_strdcpy(char *dest, char *src);

char			*ft_strnstr(const char *haystack, const char *needle, \
				size_t len);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

void			*ft_memchr(const void *str, int searchedChar, size_t n);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

void			ft_striteri(char *s, void (*f)(unsigned int, char*));

//char			*ft_itoa(int n);

char			*ft_strjoin(const char *s1, const char *s2);

char			**ft_split(const char *s, char c);

char			*ft_strtrim(const char *s1, const char *set);

/*Bonus*/

typedef struct t_LibftList
{
	void					*content;
	struct t_LibftList		*next;
}	t_LibftList;

t_LibftList		*ft_lstnew(void *content);

void			ft_lstadd_front(t_LibftList **lst, t_LibftList *new);

int				ft_lstsize(t_LibftList *lst);

//t_LibftList		*ft_lstlast(t_LibftList *lst);

void			ft_lstadd_back(t_LibftList **lst, t_LibftList *new);

void			ft_lstdelone(t_LibftList *lst, void (*del)(void *));

void			ft_lstclear(t_LibftList **lst, void (*del)(void *));

void			ft_lstiter(t_LibftList *lst, void (*f)(void *));

t_LibftList		*ft_lstmap(t_LibftList *lst, void (*f)(void *), \
					void (*del)(void *));

void			ft_fdt(char ***tab);

int				ft_printf_e(const char *s, ...);

#endif
