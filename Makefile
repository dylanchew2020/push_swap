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
BONUS	=	checker

# SOURCE CODE
SRC_DIR = ./src/
SRC		= push_swap.c swap.c push.c rotate.c reverse_rotate.c get_median.c sort.c\
			error.c push_swap_utils.c $(addprefix ps_, $(addsuffix .c, \
			lstnew lstadd_front lstsize lstlast lstadd_back lstdelone \
			lstclear))
OBJ_DIR = ./obj/
OBJ		= $(SRC:%.c=$(OBJ_DIR)%.o)

# CHECKER CODE
CHK_DIR 	= ./checker_src/
CHK			= checker.c checker_swap.c checker_push.c checker_rotate.c checker_reverse_rotate.c
CHK_OBJ_DIR = ./obj/
CHK_OBJ		= $(CHK:%.c=$(CHK_OBJ_DIR)%.o)
CHK_OBJ_ADD	= $(addprefix $(OBJ_DIR)ps_, $(addsuffix .o, \
				lstnew lstadd_front lstsize lstlast lstadd_back lstdelone \
				lstclear)) $(addprefix $(OBJ_DIR), $(addsuffix .o, \
				swap push rotate reverse_rotate get_median sort\
				error push_swap_utils))

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

ARG = "4 72 59 18 83 21 30 39 36 33 43 37 62 3 42 84 82 0 89 20 38 88 19 47 2 71 68 54 31 80 32 45 27 58 97 98 66 9 77 13 60 70 40 96 75 25 50 90 6 17 14 48 64 24 34 26 29 99 73 10 55 74 67 81 49 93 57 5 22 8 100 53 56 46 61 11 94 51 15 44 41 16 78 23 7 79 69 76 28 87 52 86 63 95 92 1 91 12 85 35"

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) $(INC) $(LIB) -o $@ #-fsanitize=address
	@ printf "$(_SUCCESS) Push_Swap Program Installation Completed\n\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ $(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	@ mkdir -p $@
	@ printf "$(_INFO) Push_Swap object directory created.\n"

$(LIBFT):
	@ printf "$(_INFO) Make Libft.\n"
	@ $(MAKE) -C $(LIBFT_DIR)
	
$(BONUS): $(CHK_OBJ)
	@ $(CC) $(CFLAGS) $(INC) $(LIB) $(CHK_OBJ) $(CHK_OBJ_ADD) -o $@ #-fsanitize=address
	@ printf "$(_SUCCESS) Checker Program Installation Completed\n\n"

$(CHK_OBJ_DIR)%.o: $(CHK_DIR)%.c
	@ $(CC) $(CFLAGS) $(INC) -c $< -o $@

run:
	@ ./push_swap -2147483649 5 4 3 2 1 
	
run2:
	@ ./push_swap $(ARG)

run3:
	@ ./push_swap $(ARG) > $(OUTPUT)

run4:
	@ ./push_swap $(ARG) | ./checker_OS $(ARG)
	
run5:
	@ ./push_swap $(ARG) | ./checker $(ARG)
	
clean:
	@ $(RM) $(OBJ) $(CHK_OBJ)
	@ $(RMDIR) $(OBJ_DIR)
	@ printf "$(_INFO) Object files & directory removed.\n"

fclean: clean
	@ $(RM) $(NAME) $(OUTPUT) $(BONUS)
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ printf "$(_INFO) Window cache cleared.\n"

re: fclean all

.PHONY: all clean fclean re
