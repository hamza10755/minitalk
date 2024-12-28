# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbelaih <hbelaih@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 09:53:43 by hbelaih           #+#    #+#              #
#    Updated: 2024/12/02 09:33:21 by hbelaih          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF = -L./libftprintf -lftprintf

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include

SERVER = server
CLIENT = client
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

INCLUDE = -I ./include

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	@make -C libftprintf
	$(CC) $(OBJS_SERVER) $(CFLAGS)  $(INCLUDE) $(FT_PRINTF) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(OBJS_CLIENT) $(CFLAGS)  $(INCLUDE) $(FT_PRINTF) -o $(CLIENT)

clean:
	@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	@rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
