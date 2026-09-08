# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cacortes <cacortes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/08 09:09:15 by cacortes          #+#    #+#              #
#    Updated: 2026/09/08 12:27:25 by cacortes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/main.cpp src/Functions.cpp src/Base.cpp src/ClassA.cpp src/ClassB.cpp src/ClassC.cpp
NAME = realType

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
BLUE = \033[0;34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(SRCS)
	@echo "$(BLUE)\nCreating the executable file $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@echo "$(GREEN)\n$(NAME) is ready.\n$(RESET)"

clean:
	@echo "$(YELLOW)\nCleaning files...\n$(RESET)"
	@rm -f $(NAME)

fclean: clean
	@echo "$(RED)\nDeleting $(NAME)...\n$(RESET)"
	@rm -f $(NAME)

re:
	@echo "$(BLUE)\nRecompiling $(NAME)...$(RESET)"
	@$(MAKE) fclean
	@$(MAKE) all