NAME = pushswap

PRINTFLIB = printf/libftprintf.a
LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

BLUE := \033[0;34m
PINK := \033[1;35m
BLUE2 := \033[0;36m
NOCOLOR := \033[0m

SRC = check_utils.c push.c push_swap.c rotate.c rotate_reverse.c \
      sort_algo.c sort_stack.c sort_three.c stack1_prep.c stack2_prep.c \
      stack_creation.c stack_utils.c stack_utils2.c stack_utils3.c swap.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): lib_compilation $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(PRINTFLIB) $(LIBFT) -o $(NAME)
	@make clean

lib_compilation :
	@echo "$(BLUE)STARTING COMPILATION"
	@cd printf && make
	@cd libft && make

clean:
	@echo "$(BLUE2)STARTING CLEANING"
	@rm -f $(OBJ)
	@cd printf && make clean
	@cd libft && make clean
	@echo "$(BLUE2)ALL OBJ FILES ARE DELETED"

fclean: clean
	@echo "$(PINK)STARTING FCLEANING"
	@rm -f $(NAME)
	@cd printf && make fclean
	@cd libft && make fclean
	@echo "$(PINK)EVERYTHING HAS BEEN CLEANED UP"

%o: %.c
	$(CC) -c $(FLAGS) $< -o $@

re:	fclean all

.PHONY: all pushswap clean fclean re
