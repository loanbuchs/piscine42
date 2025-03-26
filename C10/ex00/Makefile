# Compilateur et options
CC ?= gcc
CFLAGS ?= -Wall -Wextra -Werror

# Nom du fichier source et de l'exécutable
SRC = main.c
EXEC = ft_display_file
OBJ = $(SRC:.c=.o)

# Règle principale
all: $(EXEC)

# Compilation de l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)

# Nettoyage complet (objets + exécutable)
fclean: clean
	rm -f $(EXEC)

# Recompilation complète
re: fclean all

# Éviter les conflits avec des fichiers existants nommés "clean", "fclean" ou "re"
.PHONY: all clean fclean re

