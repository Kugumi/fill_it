NAME = fillit

LIB = libft/libft.a

SRCDIR = src/

INCDIR = 

SRC = bctr.c joskii_fillit.c perebor.c tlist.c

INC = -I libft

OBJ = (addprefix $(FILE):./*.o

FLAG = -Wall -Wextra -Werror -I. -c

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(SRC)
	@gcc $(FLAG) $(SRC)

claen:
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME)

re: fclean all
