# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sruff <sruff@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 14:34:25 by sruff             #+#    #+#              #
#    Updated: 2024/04/24 19:17:05 by sruff            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = server
NAMEC = client
NAME_BONUS = server_bonus
NAMEC_BONUS = client_bonus
SRCS = server.c
SRCSC = client.c
SRCS_BONUS = server_bonus.c
SRCSC_BONUS = client_bonus.c
OBJ = $(SRCS:.c=.o)
OBJC = $(SRCSC:.c=.o)
LIBFT = libft/libft.a
INC = -I . -I libft
CC = cc
# CFLAGS = -g
# CFLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAMEC)

$(NAME): $(SRCS)
	make -C libft
	$(CC) $(CFLAGS) $^ -o $(NAME) $(INC) -L libft -lft  

$(NAMEC): $(SRCSC)
	make -C libft
	$(CC) $(CFLAGS) $^ -o $(NAMEC) $(INC) -L libft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)	

bonus: $(NAME_BONUS) $(NAMEC_BONUS)

$(NAME_BONUS): $(SRCS_BONUS)
	make -C libft
	$(CC) $(CFLAGS) $^ -o $(NAME_BONUS) $(INC) -L libft -lft  

$(NAMEC_BONUS): $(SRCSC_BONUS)
	make -C libft
	$(CC) $(CFLAGS) $^ -o $(NAMEC_BONUS) $(INC) -L libft -lft


# $(LIBFT):
# 	make -C libft

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJC)
	@make -C libft clean

fclean: clean
	rm -f libft.a
	rm -f $(NAME) $(NAMEC)
	rm -f $(NAME_BONUS) $(NAMEC_BONUS)
	@make -C libft fclean

re: fclean all

.PHONY: all bonus norm clean fclean re