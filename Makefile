# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 16:25:03 by lserrao-          #+#    #+#              #
#    Updated: 2025/02/05 19:44:20 by lserrao-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome do executável
NAME        := minishell

# Compilador e flags
CC          := cc
CFLAGS      := -Wextra -Wall -Werror -g3
LFLAGS      := -lreadline
MAKEFLAGS   += --silent

# Cabeçalhos
HEADERS     := -I ./includes
HEADER_FILE := includes/minishell.h includes/defines.h includes/functions.h includes/structs.h

# Caminho para a libft
LIBFT_PATH  := ./lib/libft
LIBFT       := $(addprefix $(LIBFT_PATH)/, libft.a)

# Fonte
CFNCTS      :=  main/minishell.c \
				executor/executor.c \
				executor/exec_utils.c \
				executor/child.c \
				executor/expander.c \
				executor/expander_utils.c \
				parser/parser.c \
				parser/parser_utils.c \
				path/path.c \
				redirect/redirect.c \
				redirect/redirect_utils.c \
				syntax/syntax_checker.c \
				syntax/lexer.c \
				utils/utils.c \
				utils/free_utils.c \
				builtins/bi_cd.c \
				builtins/bi_echo.c \
				builtins/bi_env.c \
				builtins/bi_pwd.c \
				builtins/bi_unset.c \
				builtins/builtins.c

SRCS_PATH   := src
OBJ_PATH    := objects

# Arquivos fonte e objetos (sem subpastas para objetos)
SRCS        := $(addprefix $(SRCS_PATH)/, $(CFNCTS))
OBJS        := $(addprefix $(OBJ_PATH)/, $(CFNCTS:%.c=%.o))

# Cores
GREEN       := \033[1;32m
PURPLE      := \033[1;35m
RED         := \033[1;31m
WHITE       := \033[0;37m
BLUE        := \033[1;36m
BOLD        := \033[1;1m

# Regra padrão
all: $(OBJ_PATH) $(NAME)

debug:
	@echo "SRCS = $(SRCS)"
	@echo "OBJS = $(OBJS)"
	@echo "CFNCTS = $(CFNCTS)"
	@echo "HEADER_FILE = $(HEADER_FILE)"

# Mostra dependencias dos Objetos
depend:
	@$(CC) -MM $(CFLAGS) $(HEADERS) $(SRCS) > dependencies.mk
	@echo -e "$(GREEN)Dependencies updated in dependencies.mk!$(WHITE)"

# Regra para compilar a libft
$(LIBFT):
	@make -C $(LIBFT_PATH)

# Compilando arquivos .c em .o na pasta objects
$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c $(HEADER_FILE) | $(OBJ_PATH)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<
	@echo "$(GREEN)Compiled: $(notdir $<) ✔$(WHITE)"

# Criar o diretório objects
$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

# Criar o binário final
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(LFLAGS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)-------------------------------------------"
	@echo "$(WHITE)  ✅  The $(GREEN)SHELL$(WHITE)-E has been compiled! ✅ "
	@echo "$(GREEN)-------------------------------------------"

# Compilation.com com Valgrind
val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all -q --track-origins=yes --track-fds=yes --trace-children-skip='*/bin/*,*/sbin/*' --suppressions=.readline.supp ./$(NAME)

# Limpeza dos objetos
clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(WHITE)     The objects are cleaned now!"

# Limpeza completa (objetos e binário)
fclean: clean
	@echo "$(WHITE)     Cleaning all objects and binaries..."
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(WHITE)    Cleaning $(BLUE)MINISHELL$(WHITE) complete!"

# Recompilar tudo
re: fclean all

# Especificando que esses alvos não são arquivos
.PHONY: all, clean, fclean, re
