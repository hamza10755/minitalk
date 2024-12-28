# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/15 13:20:22 by hbelaih           #+#    #+#              #
#    Updated: 2024/09/15 13:22:37 by hbelaih          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_printf.c printf_functions.c printf_functions2.c printf_functionsU.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

clean : 
	rm -rf $(OBJS)

fclean : clean 
	rm -rf $(NAME)
	
re : fclean all
