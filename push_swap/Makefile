# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 13:10:31 by aboukdid          #+#    #+#              #
#    Updated: 2024/02/20 13:14:24 by aboukdid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap
SRCS = ft_atoi.c ft_split.c ft_strjoin.c list_help.c main.c parsing.c push.c \
		reverse_rotate.c rotate.c sort_pivot.c sort_five.c sort_three_and_four.c swap.c utils.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	 $(CC)  $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< 

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean