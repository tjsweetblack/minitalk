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

NAME = server_and_client
SERVER = server
CLIENT = client
CFLAGS = -Wall -Werror -Wextra
CC = gcc
SRC_DIR = ./ft_printf
SERVER_SRC = server.c
CLIENT_SRC = client.c
COMMON_SRC = $(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_printf_utils.c $(SRC_DIR)/libft_utils.c  # Add common source files here
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
COMMON_OBJ = $(COMMON_SRC:.c=.o)

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(COMMON_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(COMMON_OBJ) -o $(SERVER)
	@echo "Server Is Ready!"

$(CLIENT): $(CLIENT_OBJ) $(COMMON_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(COMMON_OBJ) -o $(CLIENT)
	@echo "Client Is Ready!"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(COMMON_OBJ)
	@echo "Object files have been cleaned successfully"

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client have been fully cleaned successfully"

re: fclean all
