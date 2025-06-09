# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lserrao- <lserrao-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 16:25:03 by lserrao-          #+#    #+#              #
#    Updated: 2025/02/16 20:14:35 by lserrao-         ###   ########.fr        #
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
				builtins/bi_export.c \
				builtins/bi_exit.c \
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
DEFAULT		:= \033[0;0m

# Regra padrão
all: $(OBJ_PATH) $(NAME)

# Conta total de arquivos
TOTAL_FILES := $(words $(SRCS))
COMPILED_FILES := 0

# Função para atualizar a barra de progresso
define update_progress
	@$(eval COMPILED_FILES=$(shell echo $$(($(COMPILED_FILES) + 1))))
	@$(eval PERCENTAGE=$(shell echo $$(($(COMPILED_FILES) * 100 / $(TOTAL_FILES)))))
	@printf "\r\033[0;37mCompiling: ["
	@if [ $(PERCENTAGE) = 100 ]; then \
		for i in `seq 1 $(shell echo $$(($(PERCENTAGE) / 5)))`; do printf "$(GREEN)█$(WHITE)"; done; \
	else \
		for i in `seq 1 $(shell echo $$(($(PERCENTAGE) / 5)))`; do printf "$(DEFAULT)█$(WHITE)"; done; \
	fi
	@for i in `seq 1 $(shell echo $$((20 - $(PERCENTAGE) / 5)))`; do printf " "; done
	@if [ $(PERCENTAGE) = 100 ]; then \
		printf "] $(GREEN)%d%%$(DEFAULT)" $(PERCENTAGE); \
	else \
		printf "] %d%%" $(PERCENTAGE); \
	fi
	@if [ $(PERCENTAGE) = 100 ]; then printf "\n"; fi
endef

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
	$(call update_progress)

# Criar o diretório objects
$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

# Criar o binário final
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(OBJS) $(LIBFT) $(LFLAGS) $(HEADERS) -o $(NAME)
	@clear
	@echo "$(GREEN)-------------------------------------------"
	@echo "$(WHITE)  ✅  The \033[1;32mSHELL\033[1;37m\002-E\033[0m$(WHITE) has been compiled! ✅ $(DEFAULT)"
	@echo "$(GREEN)-------------------------------------------$(WHITE)"

# Compilation.com com Valgrind
val: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --trace-children-skip='*/bin/*,*/sbin/*' --suppressions=.readline.supp ./$(NAME)

# Limpeza dos objetos
clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(WHITE)     The $(PURPLE)objects$(WHITE) are cleaned now!$(DEFAULT)"

# Limpeza completa (objetos e binário)
fclean: clean
	@echo "$(WHITE)     Cleaning all $(PURPLE)objects$(WHITE) and binaries..."
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "$(WHITE)    Cleaning \033[1;32mSHELL\033[1;37m-E $(WHITE)complete!$(DEFAULT)"

# Recompilar tudo
re: fclean all

# Especificando que esses alvos não são arquivos
.PHONY: all, clean, fclean, re
