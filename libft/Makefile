# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okaname <okaname@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 20:14:46 by okaname           #+#    #+#              #
#    Updated: 2025/05/12 23:19:30 by okaname          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memchr.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c\

SRCS_BONUS =	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

SRCS_EXTRA = ft_get_longer_length.c\
				ft_strcmp.c \
				get_next_line.c\
				get_next_line_utils.c\
				ft_atof.c\
				ft_free_array.c\
				ft_pow.c\



OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_EXTRA = $(SRCS_EXTRA:.c=.o)

TARGET = $(NAME)
BONUS_FLAG = .bonus_done


all: $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $@ $^

bonus:$(BONUS_FLAG)

$(BONUS_FLAG):$(OBJS) $(OBJS_BONUS) $(OBJS_EXTRA)
	ar rcs $(TARGET) $^
	touch $(BONUS_FLAG)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS) $(OBJS_EXTRA) $(BONUS_FLAG)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all bonus clean fclean re
