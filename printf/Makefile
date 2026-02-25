NAME = libftprintf.a

SRC = ft_printchar.c ft_printdecimalint.c ft_printf.c \
      ft_printhexa.c ft_printstr.c ft_printptr.c \
      ft_printunsigned.c \

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

BLUE := \033[0;34m
PINK := \033[1;35m
BLUE2 := \033[0;36m

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) -rcs $@ $^
	@echo "$(BLUE)COMPILATION DONE"

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(BLUE2)CLEAN ALL THE OBJ"
	
fclean: clean
	@rm -f $(NAME)
	@echo "$(PINK)CLEAN EVERYTHING"

re: fclean all

.PHONY: all clean fclean re
