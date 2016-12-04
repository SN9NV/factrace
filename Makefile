# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/09 12:47:08 by adippena          #+#    #+#              #
#    Updated: 2016/12/04 13:21:16 by adippena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	factrace
INC			=	include
CFLAGS		=	-Wall -Wextra -Werror -Wno-unused-result -g3 -I $(INC)
LFLAGS		=	-lgmp
CC			=	gcc
LD			=	gcc

INCLUDE		=	$(shell find include -name "*.h")
SRC			=	$(shell find src -name "*.c")
OBJ			=	$(SRC:src/%.c=build/%.o)

all: factrace

build/%.o: src/%.c $(INCLUDE)
	@echo "\033[92m    CC    $@\033[0m"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

factrace: $(OBJ)
	@echo "\033[92m    LD    $(NAME)\033[0m"
	@$(LD) $^ $(LFLAGS) -o $(NAME)

clean:
	@echo "\033[92m    RM    object files\033[0m"
	@rm -rf build

fclean: clean
	@echo "\033[92m    RM    $(NAME)\033[0m"
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM

re: fclean all
