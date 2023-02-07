/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:50:41 by ilandols          #+#    #+#             */
/*   Updated: 2022/12/07 17:52:29 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "../libs/ft_printf/include/ft_printf.h"
# include "../libs/ft_get_next_line/include/get_next_line.h"
# include "../libs/linked_lists/include/linked_lists.h"
# include <stdlib.h>
# include <unistd.h>

typedef enum e_bool {
	FALSE,
	TRUE
}			t_bool;

typedef struct s_pos {
	int	x;
	int	y;
}				t_pos;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

long long	ft_long_long_atoi(const char *nptr);
void		ft_print_array(char **elements);
int			ft_get_size_array(char **elements);
void		ft_free_array(char **elements);
void		ft_delete_content(int *content);
void		ft_print_bits(int byte);
int			ft_iswhitespace(int c);
int			ft_islower(int c);
int			ft_get_size_number(int number);
char		**ft_get_file_content(int fd);
void		ft_print_exit(char *str);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_pathjoin(char const *s1, char const *s2);
char		*ft_strcut_left(char const *s, int c);
char		*ft_strcut_right(char const *s, int c);
void		ft_perror_exit(char *str);
char		**ft_split_charset(char const *s, char *charset);
char		*ft_strjoin_free(char *s1, char *s2);
char		*ft_delete_char(char *str, size_t index);
int			ft_str_isalnum(char *str);
int			ft_str_isalpha(char *str);
int			ft_str_isdigit(char *str);
int			ft_strrncmp(const char *s1, const char *s2, size_t n);

#endif
