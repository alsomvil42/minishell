# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsomvil <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 17:04:04 by alsomvil          #+#    #+#              #
#    Updated: 2018/09/19 12:29:48 by alsomvil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = srcs/main.c \
	  srcs/main_two.c \
	  srcs/buildin.c \
	  srcs/buildin_two.c \
	  srcs/buildin_three.c \
	  srcs/duplicate_tab.c \
	  srcs/forfreetab.c \
	  srcs/get_info.c \
	  srcs/set_env.c \
	  srcs/set_env_two.c \
	  srcs/work_to_env.c \
	  srcs/ft_strcmp.c \
	  srcs/ft_split_whitespaces.c \
	  srcs/ft_strsplit.c \
	  srcs/get_next_line.c \
	  srcs/ft_echo.c \

OBJ = $(SRC:.c=.o)
CC = gcc -g -Wall -Wextra -Werror
NAME = minishell
_GREEN = $ \033[32m
_YELLOW = $ \033[33m
_YELLOW_S = $ \033[4;33m
_RED = $ \033[31m
_END = $ \033[0m


all : $(NAME)

$(NAME): $(OBJ)
	@echo "$(_YELLOW)|==>$(_END)$(_YELLOW_S)Compilation de printf:$(_END)" ; $(MAKE) -C ft_printf
	@sleep 0.3
	@echo "$(_YELLOW)|=>$(_END)$(_GREEN) printf compiled [✓]$(_END)"
	@sleep 0.3
	@echo "$(_YELLOW)|==>$(_END)$(_YELLOW_S)Compilation de minishell:$(_END)"
	@sleep 0.5
	@$(CC) -g3 -o $(NAME) -I. -I./ft_printf $(OBJ) ft_printf/ftprintf.a
	@echo "$(_YELLOW)|=>$(_END)$(_GREEN) minishell compiled [✓]$(_END)"

%.o: %.c
	@$(CC) -c $(CFLAGS) -I. -I./ft_printf $< -o $@

clean:
	@$(MAKE) clean -C ft_printf
	@rm -f $(OBJ)
	@sleep 0.3
	@echo "$(_YELLOW)|==>$(_END)$(_YELLOW_S)Suppresion des fichiers objets (clean):$(_END)"
	@sleep 0.3
	@echo "$(_YELLOW)|=>$(_END)$(_RED) ft_printf cleaned $(_END)$(_GREEN)[✓]$(_END)"
	@sleep 0.3
	@echo "$(_YELLOW)|=>$(_END)$(_RED) minishell cleaned $(_END)$(_GREEN)[✓]$(_END)"

fclean: clean
	@$(MAKE) fclean -C ft_printf
	@sleep 0.3
	@echo "$(_YELLOW)|$(END)"
	@sleep 0.3
	@echo "$(_YELLOW)|==>$(_END)$(_YELLOW_S)Suppresion de l'executable (fclean):$(_END)"
	@rm -f $(NAME)
	@sleep 0.3
	@echo "$(_YELLOW)|=>$(_END)$(_RED) executable cleaned$(_END) $(_GREEN)[✓]$(_END)"
	@echo "$(_YELLOW)|$(END)"

re: fclean all

.PHONY: ft_printf clean fclean all re
