# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: badriano <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 11:48:27 by badriano          #+#    #+#              #
#    Updated: 2024/07/29 11:48:32 by badriano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra
CC = gcc
FLAGS = -Wall -Wextra -Werror

all:
	@gcc $(FLAGS) server.c ./ft_printf/*.c -o $(SERVER)
	@gcc $(FLAGS) client.c ./ft_printf/*.c -o $(CLIENT)
	@echo "Server And Client Are Ready!"

fclean:
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client Have Been Cleaned Successfully"

re: fclean all
