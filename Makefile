# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchew <lchew@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 17:13:24 by lchew             #+#    #+#              #
#    Updated: 2022/05/14 22:01:24 by lchew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name:
NAME	=	push_swap

# SOURCE CODE
SRC_DIR = ./
SRC	= push_swap.c swap.c push.c rotate.c reverse_rotate.c get_median.c sort.c\
		error.c $(addprefix ps_, $(addsuffix .c, \
		lstnew lstadd_front lstsize lstlast lstadd_back lstdelone \
		lstclear))
OBJ_DIR = ./obj/
OBJ	=	$(SRC:%.c=$(OBJ_DIR)%.o)

# LIBFT LIBRARY
LIBFT_DIR = ./libft/
LIBFT = libft.a

# -L "folder" to looks for library in the folder
# -l(ft) to link library file. l replaces lib
LIB := -lft -L./libft

# HEADER
INC_DIR = ./
INC		= -I$(INC_DIR)

# COMPILATION
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

# REMOVE FILES OR DIRECTORIES
RM = rm -f
RMDIR = rmdir

# PRETTY
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

# OUTPUT
OUTPUT = output.txt

ARG = "5 9 13 15 16 8 19 6 11 2 4 12 10 3 7 14 18 20 1 17"

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@ ${CC} $(CFLAGS) ${OBJ} $(INC) ${LIB} -o $@ #-fsanitize=address
	@ printf "$(_SUCCESS) Program Installation Completed\n\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)
	@ printf "$(_INFO) Libft object directory created.\n"

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR)

run:
	@ ./push_swap 2147483648 0 -1 1 2147483647 -2147483648
	
run2:
	@ ./push_swap $(ARG)

run3:
	@ ./push_swap $(ARG) > $(OUTPUT)

run_checker:
	@ ./push_swap $(ARG) | ./checker_MAC $(ARG)
	
clean:
	@ $(RM) $(OBJ)
	@ $(RMDIR) $(OBJ_DIR)
	@ printf "$(_INFO) Object files & directory removed.\n"

fclean: clean
	@ $(RM) $(NAME) $(OUTPUT)
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ printf "$(_INFO) Window cache cleared.\n"

re: fclean all

.PHONY: all clean fclean re
