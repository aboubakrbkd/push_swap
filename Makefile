# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboukdid <aboukdid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 13:10:31 by aboukdid          #+#    #+#              #
#    Updated: 2024/02/22 12:45:52 by aboukdid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = push_swap
NAME_BONUS = checker
SRCS = ft_atoi.c ft_split.c ft_strjoin.c list_help.c main.c parsing.c push.c \
		reverse_rotate.c rotate.c sort_pivot.c sort_five.c sort_three_and_four.c swap.c utils.c
SRCB = bonus/ft_atoi_bonus.c bonus/ft_split_bonus.c bonus/ft_strjoin_bonus.c bonus/list_help_bonus.c \
		bonus/main_bonus.c bonus/parsing_bonus.c bonus/push_bonus.c \
		bonus/reverse_rotate_bonus.c bonus/rotate_bonus.c bonus/swap_bonus.c bonus/utils_bonus.c bonus/utils1_bonus.c bonus/gnl_bonus.c bonus/ft_strncmp_bonus.c
OBJS = $(SRCS:.c=.o)
OBJBS = $(SRCB:.c=.o)

$(NAME): $(OBJS)
	 $(CC)  $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

%_bonus.o: %_bonus.c bonus/push_swap_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
	
bonus: $(OBJBS)
	$(CC)  $(CFLAGS) $(OBJBS) -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS) $(OBJBS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
