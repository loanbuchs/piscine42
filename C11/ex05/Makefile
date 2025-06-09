# Nom de l'exécutable
NAME = do-op

# Dossiers
SRC_DIR = srcs
INC_DIR = includes

# Fichiers source
SRC = main.c $(SRC_DIR)/operations.c
OBJ = $(SRC:.c=.o)

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

# Règles
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
