NAME = libft.a
CC = cc
HEADER = ./
FLAGS = -Wall -Werror -Wextra
SRC = ft_isdigit.c \
				 ft_isalpha.c \
				 ft_isalnum.c \
				 ft_isascii.c \
				 ft_isprint.c \
				 ft_memset.c \
				 ft_bzero.c \
				 ft_memcpy.c \
				 ft_memmove.c \
				 ft_strlen.c \
				 ft_strlcpy.c \
				 ft_strlcat.c \
				 ft_toupper.c \
				 ft_tolower.c \
				 ft_strchr.c \
				 ft_strrchr.c \
				 ft_strncmp.c \
				 ft_memchr.c \
				 ft_memcmp.c \
				 ft_strnstr.c \
				 ft_atoi.c \
				 ft_calloc.c \
				 ft_strdup.c \
				 ft_substr.c \
				 ft_putchar_fd.c \
				 ft_putstr_fd.c \
				 ft_putendl_fd.c \
				 ft_putnbr_fd.c \
				 ft_striteri.c \
				 ft_strmapi.c \
				 ft_strtrim.c \
				 ft_itoa.c \
				 ft_split.c

SRC_BONUS = ft_lstnew_bonus.c \
				 ft_lstadd_front_bonus.c \
				 ft_lstsize_bonus.c \
				 ft_lstlast_bonus.c \
				 ft_lstadd_back_bonus.c \
				 ft_lstdelone_bonus.c \
				 ft_lstclear_bonus.c \
				 ft_lstiter_bonus.c \
				 ft_lstmap_bonus.c

SRC_NEW_FUN = ./get_next_line/get_next_line.c \
				 ./get_next_line/get_next_line_utils.c

OBJ = ${SRC:%.c=%.o}
OBJ_BONUS = ${SRC_BONUS:%.c=%.o}
OBJ_NEW_FUN = ${SRC_NEW_FUN:%.c=%.o}

${NAME}: ${OBJ}

all: ${NAME}
	@echo "Libft functions compiled successfully!"
 
bonus: ${OBJ_BONUS}
	@echo "Bonus functions compiled successfully!"

new_fun: ${OBJ_NEW_FUN}
	@echo "Additional functions compiled successfully!"

clean:
	@echo "Cleaning Libft objects..."
	@rm -f ${OBJ} ${OBJ_BONUS}
	@echo "Cleaning Get_next_line objects..."
	@rm -f ${OBJ_NEW_FUN}
	@echo "Done!"

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f ${NAME}
	@echo "Done!"

re: fclean all

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER)
	@ar rcs ${NAME} $@

.PHONY: bonus all clean fclean re
