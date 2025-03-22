# Makefile

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Répertoires
SRCDIR = srcs
INCDIR = includes

# Liste des fichiers sources et transformation en fichiers objets
SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS = $(SRCS:.c=.o)
OBJPATHS = $(addprefix $(SRCDIR)/, $(OBJS))

# Nom de la bibliothèque
LIB = libft.a

# Règle par défaut : all
all: $(LIB)

# Création de la bibliothèque statique
$(LIB): $(OBJPATHS)
	ar rcs $(LIB) $(OBJPATHS)

# Règle générique pour compiler chaque .c en .o à côté du source
$(SRCDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/ft.h
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Règle clean : supprimer les fichiers objets
clean:
	rm -f $(OBJPATHS)

# Règle fclean : clean + suppression de la librairie
fclean: clean
	rm -f $(LIB)

# Règle re : reconstruction complète
re: fclean all

