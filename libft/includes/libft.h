/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:10:33 by qhonore           #+#    #+#             */
/*   Updated: 2016/09/23 04:31:02 by qhonore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 20

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*back;
	struct s_dlist	*next;
}				t_dlist;

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
int				ft_putchar(char c);
int				ft_putstr(char const *s);
void			ft_putendl(char const *s);
int				ft_putnbr(int n);
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
int				ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_isspace(int c);
int				ft_isblank(int c);
int				ft_strprefix(const char *str, const char *prefix);
int				ft_strsuffix(const char *str, const char *suffix);
size_t			ft_lstgo(t_list **alst, size_t n);
int				ft_lstaddend(t_list **alst, t_list *new);
int				ft_intlen(int n);
void			ft_lstprint(t_list *list);
int				ft_lstndel(t_list **alst, size_t n);
int				ft_atoi_base(const char *str, int str_base);
int				ft_abs(int nb);
double			ft_dabs(double nb);
float			ft_fabs(float nb);
long			ft_labs(long nb);
int				ft_pow(int nb, int pow);
int				ft_strisnb(const char *str);
int				get_next_line(int const fd, char **line);
t_dlist			*ft_dlstnew(void const *content, size_t content_size);
void			ft_dlstadd(t_dlist **dlst, t_dlist *new);
void			ft_dlstaddend(t_dlist **dlst, t_dlist *new);
size_t			ft_dlstgo(t_dlist **dlst, size_t n, int dir);
int				ft_dlstndel(t_dlist **dlst, size_t n, int dir);
int				ft_free(void **mem);
char			*ft_itoa(int n);
char			*ft_ltoa(long nbr);
char			*ft_lltoa(long long nbr);
char			*ft_sctoa(signed char nbr);
char			*ft_sitoa(short int nbr);
char			*ft_imtoa(intmax_t nbr);
char			*ft_stoa(size_t nbr);
char			*ft_uitoa(unsigned int n);
char			*ft_ultoa(unsigned long nbr);
char			*ft_ulltoa(unsigned long long nbr);
char			*ft_uctoa(unsigned char nbr);
char			*ft_usitoa(unsigned short int nbr);
char			*ft_uimtoa(uintmax_t nbr);
char			*ft_itoa_base(int value, int base, int upper);
char			*ft_ltoa_base(long value, int base, int upper);
char			*ft_lltoa_base(long long value, int base, int upper);
char			*ft_imtoa_base(intmax_t nb, int base, int upper);
char			*ft_stoa_base(size_t nb, int base, int upper);
char			*ft_uitoa_base(unsigned int value, int base, int upper);
char			*ft_ultoa_base(unsigned long value, int base, int upper);
char			*ft_ulltoa_base(unsigned long long value, int base, int upper);
char			*ft_usitoa_base(unsigned short int value, int base, int upper);
char			*ft_uctoa_base(unsigned char value, int base, int upper);
char			*ft_uimtoa_base(uintmax_t nb, int base, int upper);

#endif
