/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremcht <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:02:35 by akremcht          #+#    #+#             */
/*   Updated: 2022/05/31 01:42:55 by akremcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

typedef struct s_parm_lst
{
	char				**content;
	char				**output_redirect;
	char				**input_redirect;
	struct s_parm_lst	*next;
}	t_parm_lst;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t len);
size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dest, const char *src, size_t dstsize);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *str, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_parm_lst	*ft_lstnew(char **content);
void		ft_lstadd_front(t_parm_lst **lst, t_parm_lst *new);
int			ft_lstsize(t_parm_lst *lst);
t_parm_lst	*ft_lstlast(t_parm_lst *lst);
void		ft_lstadd_back(t_parm_lst **lst, t_parm_lst *new);
void		ft_lstdelone(t_parm_lst *lst, void (*del)(void*));
void		ft_lstclear(t_parm_lst **lst, void (*del)(void*));
void		ft_lstiter(t_parm_lst *lst, void (*f)(void *));
t_parm_lst	*ft_lstmap(t_parm_lst *lst,
				void *(*f)(void *), void (*del)(void *));
char		*get_next_line(int fd);
char		*get_line(char *str);
char		*get_rest(char *str);

#endif