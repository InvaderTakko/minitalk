# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sruff <sruff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 14:34:25 by sruff             #+#    #+#              #
#    Updated: 2024/04/09 15:10:00 by sruff            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSLIBFT = \
ft_atoi.c ft_bzero.c ft_calloc.c\
ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
ft_tolower.c ft_toupper.c \
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c\
ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
SRCSPRINTF = ft_printf_bonus.c ft_printf_hex_bonus.c ft_printf_decimal_bonus.c ft_printf_str_bonus.c ft_printf_pointer_bonus.c ft_printf_bonus_bonus.c
SRCSGETNEXTLINE = get_next_line.c get_next_line_utils.c
SRC = $(addprefix libft/, $(SRCSLIBFT)) $(addprefix ft_printf/, $(SRCSPRINTF)) $(addprefix get_next_line/, $(SRCSGETNEXTLINE))
OBJ = $(SRC:%.c=%.o)

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I .

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all