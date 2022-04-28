/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrhyhorn <mrhyhorn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:57:40 by mrhyhorn          #+#    #+#             */
/*   Updated: 2022/04/11 16:14:58 by mrhyhorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

/*libft*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *dest, int c, size_t len);
void		ft_bzero(void *s, size_t n);
int			ft_max(int a, int b);
float		ft_fmax(float a, float b);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strcpy(char *dst, const char *src);
size_t		ft_strlcat(char *dest, const char *src, size_t dstsize);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_abs(int num);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
long long	ft_atoll(const char *str);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(const char *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*get_next_line*/
# define BUFFER_SIZE 1

char		*get_next_line(int fd);
char		*ft_read_from_buffer(int fd, char *save_line);
char		*ft_clear_save_line(char *save_line);
char		*ft_delete_clear_line(char *save_line);
int			ft_has_new_line(char *save_line);
char		*ft_new_strjoin(char *save_line, char *rd_buffer);
void		*ft_memcpy(void *dst, const void *src, size_t n);
size_t		ft_strlen(const char *s);

/*ft_printf*/
int			ft_printf(const char *format_str, ...);
int			ft_parse_str(const char *format_str, va_list argp);
int			ft_define_conv(char conv, va_list argp);
void		ft_putstr(const char *str);
int			ft_putstr_num(const char *str);
void		ft_putchar(char c);
int			ft_putchar_num(int c);
int			ft_putnbr_num(int nbr);
int			ft_count_num(int nbr);
void		ft_putnbr(int nbr);
int			ft_puthex_num(unsigned int x, char conv);
int			ft_count_hex(unsigned int x);
void		ft_puthex_up(unsigned int x);
void		ft_puthex_low(unsigned int x);
int			ft_count_ptr(unsigned long ptr);
int			ft_putptr_num(void *ptr);
void		ft_putptr(unsigned long ptr);
int			ft_count_uint(unsigned int uint);
int			ft_putuint_num(unsigned int uint);
void		ft_putuint(unsigned int uint);

#endif
