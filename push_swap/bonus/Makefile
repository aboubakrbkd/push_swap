# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 13:10:31 by aboukdid          #+#    #+#              #
#    Updated: 2024/02/22 10:15:26 by aboukdid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf
NAME = checker
SRCS = ft_atoi_bonus.c ft_split_bonus.c ft_strjoin_bonus.c list_help_bonus.c main_bonus.c parsing_bonus.c push_bonus.c \
		reverse_rotate_bonus.c rotate_bonus.c swap_bonus.c utils_bonus.c utils1.c gnl.c ft_strncmp_bonus.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	 $(CC)  $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%.o: %.c ../push_swap.h
	$(CC) $(CFLAGS) -c $< 

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean