##
## EPITECH PROJECT, 2018
## strace
## File description:
## makefile
##

CC	= gcc

RM	= rm -f

NAME	= strace

SRC	= src/main.c \
	  src/display_sys.c\
	  src/trace.c\
	  src/display_arg.c\
	  src/display_ard2.c\
	  src/utility.c

OBJ	=$(SRC:.c=.o)

ifeq ($(DEBUG),1)
CFLAGS	+= -g3 -ggdb
endif

CFLAGS	+= -W -Wall -Wextra -fno-stack-protector -I./inc # -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
