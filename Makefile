NAME = push_swap
SRC = main.c ft_split.c checks.c pushops.c pushswap.c revrotops.c rotops.c swapops.c trisort.c utils.c
CC = gcc
CFLAGS = -Wall -Werror -Wextra
HEADER = push_swap.h
RM = rm -rf
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	${RM} ${OBJ}
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY : all clean fclean re

