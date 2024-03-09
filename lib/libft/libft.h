/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:06:11 by leobarbo          #+#    #+#             */
/*   Updated: 2024/03/09 18:28:24 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_element
{
	void				*content;
	struct s_element	*next;
	struct s_element	*prev;
}	t_element;

typedef struct s_dolist
{
	t_element	*first;
	t_element	*last;
	size_t		size;
}	t_dolist;

int			ft_isprint(int c);
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t n);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isspace(int c);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
size_t		ft_strlen(const char *s);
char		*ft_strnstr(const char *str, const char *substr, size_t len);
char		*ft_strrchr(const char *str, int ch);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void*));
int			ft_lstsize(t_list *lst);
void		ft_free_split(char **split);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));
t_element	*ft_lstpickel(t_dolist *lst, int index);
t_element	*ft_lstpop(t_dolist *lst, int index);
t_element	*ft_lstnewelement(void *content);
void		ft_lstadd_after(t_dolist *lst, t_element *ref, t_element *el);
void		ft_lstadd_before(t_dolist *lst, t_element *ref, t_element *el);
long		ft_atol(const char *str);

#endif
