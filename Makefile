.PHONY: all clean fclean re

CHECKER = checker
PUSH_SWAP = push_swap
CC = gcc
FLAGS = -Wall -Wextra -Werror -O2

# LIBFT
LIB_DIR := libft
LIB_INC := $(LIB_DIR)/libft.h
LIB := $(LIB_DIR)/libft.a
LIB_RULE = $(addsuffix .lib, $(DIRLIB)/)

PUSH_SWAP_INC = includes/push_swap.h

PUSH_SWAP_LIB =	check_ascending_oder.c		fill_stack.c		find_extremum.c					is_digit.c			\
				main_sort.c					pb.c				rra_rrb.c						sort_five_nums.c		\
				clean_memory.c				final_sort.c		find_position.c					is_repeat.c			\
				one_part_stack_a.c			ra_rb.c				rrr.c							sort_three_nums.c		\
				exec_command.c				find_command.c		functions_for_main_sort.c		lst_new.c				\
				pa.c						rr.c				sa_sb.c							ss.c
PUSH_SWAP_LIB := $(addprefix push_swap_library/, $(PUSH_SWAP_LIB))

CHECKER_SRC = src_checker/checker.c
PUSH_SWAP_SRC = src_push_swap/push_swap.c

all: $(LIB_RULE) $(CHECKER) $(PUSH_SWAP)

%.lib:
	@$(MAKE) -sC $(LIB_DIR)

$(CHECKER) : $(PUSH_SWAP_LIB) $(CHECKER_SRC) $(PUSH_SWAP_INC) $(LIB)
	@$(CC) $(FLAGS) $(PUSH_SWAP_LIB) $(CHECKER_SRC) $(LIB) -I $(LIB_INC) -o $(CHECKER)
	@echo "CHECKER COMPILED"

$(PUSH_SWAP) : $(PUSH_SWAP_LIB) $(PUSH_SWAP_SRC) $(PUSH_SWAP_INC) $(LIB)
	@$(CC) $(FLAGS) $(PUSH_SWAP_LIB) $(PUSH_SWAP_SRC) $(LIB) -I $(LIB_INC) -o $(PUSH_SWAP)
	@echo "PUSH_SWAP COMPILED"

clean:
	@rm -f checker push_swap

fclean: clean
	@make fclean -C $(LIB_DIR)

re: fclean all
