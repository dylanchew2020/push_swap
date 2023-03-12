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
		$(addprefix ps_, $(addsuffix .c, \
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

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@ ${CC} $(CFLAGS) ${OBJ} $(INC) ${LIB} -o $@ -fsanitize=address
	@ printf "$(_SUCCESS) Program Installation Completed\n\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)
	@ printf "$(_INFO) Libft object directory created.\n"

$(LIBFT):
	@ $(MAKE) -C $(LIBFT_DIR)

run:
	@ ./push_swap 302 997 335 769 686 782 705 536 405 553 881 154 293 935 88 254 726 234 22 371 31 766 631 60 320 388 983 576 313 693 933 459 205 607 463 225 349 967 355 703 107 47 491 905 845 811 998 11 442 378 30 45 772 694 610 7 488 916 761 391 4 842 855 194 443 776 85 826 255 672 956 851 81 608 433 202 521 616 675 890 148 55 1000 762 437 800 698 814 539 785 25 322 70 518 924 87 724 837 102 114
		
run2:
	@ ./push_swap "2 8 13 5 15 7 6 10 4 14 12 1 9 11 3"
	
clean:
	@ $(RM) $(OBJ)
	@ $(RMDIR) $(OBJ_DIR)
	@ printf "$(_INFO) Object files & directory removed.\n"

fclean: clean
	@ $(RM) $(NAME)
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ printf "$(_INFO) Window cache cleared.\n"

re: fclean all

.PHONY: all clean fclean re
