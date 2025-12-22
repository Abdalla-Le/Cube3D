/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:04:30 by ancarlos          #+#    #+#             */
/*   Updated: 2025/04/21 19:26:38 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <stdlib.h>
#include <unistd.h>

char	*ft_strjoin(const char  *s1, const char  *s2);
char	*ft_strchr(const char *s1, int c);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strdup(const char *src);
char *get_next_line(int fd);


#endif
