NAME = fillit

SRC =	bctr.c joski_fillit.c perebor.c tlist.c freetlist.c

INCLUDES = -I ./includes
OBJECTS = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = gcc
LIBFT = ./libft/libft.a
LIBLINK = -L ./libft -lft
LIBINK = -I ./libft

all: $(NAME)

%.o:%.c
	@$(CC) $(FLAGS) $(LIBINK) $(INCLUDES) -o $@ -c $< -g

libft: $(LIBFT)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft
	@echo "OK"

$(NAME): libft $(OBJECTS)
	@echo "Compiling fillit..."
	@$(CC) $(LIBLINK) -o $(NAME) $(OBJECTS) -g
	@echo "OK"

rmlib:
	@echo "Deliting libft objects files..."
	@make fclean -C ./libft
	@echo "OK"

clean: rmlib
	@echo "Deliting fillit objects files..."
	@rm -rf $(OBJECTS)
	@echo "OK"

fclean: clean
	@echo "Deliting fillit..."
	@rm -rf $(NAME)
	@echo "OK"

re: fclean all