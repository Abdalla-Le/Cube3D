/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:20:46 by ancarlos          #+#    #+#             */
/*   Updated: 2025/12/22 15:50:26 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
#define TRUE 1;
#define FALSE 0;

int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);
int		ft_isalnum(int c);
char	ft_isalpha(int c);
int		ft_isascii(int n);
int		ft_isdigit(int n);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *ptr, int value, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s1, int c);
char	*ft_strdup(const char *src);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s1, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t size);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		perc_xupper(unsigned long nb);
int		perc_x(unsigned long nb);
int		perc_u(unsigned int nb);
int		perc_s(char *s);
int		perc_p(void	*p);
int		perc_d(int nb);
int		perc_c(int c);
int		ft_printf(const char *print, ...);
int	    my_free_matrix(char **matrix);
char	*my_strndup(const char *s, size_t n);
int     my_strcmp(char *s1, char *s2);



#endif
