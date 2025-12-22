# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 17:31:25 by ancarlos          #+#    #+#              #
#    Updated: 2025/12/22 16:22:36 by ancarlos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libft.a

MY_SOUCERS =	ft_atoi.c    ft_isalnum.c  ft_isdigit.c  ft_memchr.c  ft_memmove.c     ft_putendl_fd.c  ft_split.c   ft_striteri.c  ft_strlcpy.c  ft_strncmp.c  ft_strrchr.c  ft_tolower.c \
				ft_bzero.c   ft_isalpha.c  ft_isprint.c  ft_memcmp.c  ft_memset.c      ft_putnbr_fd.c   ft_strchr.c  ft_strjoin.c   ft_strlen.c   ft_strnstr.c    ft_strtrim.c  ft_toupper.c \
				ft_calloc.c  ft_isascii.c  ft_itoa.c     ft_memcpy.c  ft_putchar_fd.c  ft_putstr_fd.c   ft_strdup.c  ft_strlcat.c   ft_strmapi.c  ft_strnstr.c  ft_substr.c  perc_c.c  perc_d.c \
				perc_p.c     perc_s.c      perc_u.c      perc_x.c     perc_xupper.c    ft_printf.c	my_free_matrix.c my_strndup.c my_strcmp.c get_next_line_utils.c get_next_line.c

CFLAGS = -Wall -Werror -Wextra

OBJS = $(MY_SOUCERS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


