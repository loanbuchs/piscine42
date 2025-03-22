#!/bin/bash
# libft_creator.sh
# Ce script compile tous les fichiers .c du répertoire courant en fichiers objets,
# puis les archive dans la bibliothèque statique libft.a.
# Il supprime ensuite les fichiers objets pour un répertoire propre.

# Options de compilation
CC="gcc"
CFLAGS="-Wall -Wextra -Werror"

# Vérifier la présence de fichiers sources
SRC_FILES=$(find . -maxdepth 1 -name "*.c")
if [ -z "$SRC_FILES" ]; then
    echo "Aucun fichier source (.c) trouvé dans le répertoire courant."
    exit 1
fi

echo "Compilation des fichiers sources..."
# Compilation de chaque fichier source en fichier objet
for file in $SRC_FILES; do
    echo "Compilation de $file..."
    $CC $CFLAGS -c "$file" -o "${file%.c}.o"
done

echo "Création de la bibliothèque libft.a..."
# Création de l'archive statique libft.a
ar rcs libft.a *.o

echo "Nettoyage des fichiers objets..."
rm -f *.o

echo "La bibliothèque libft.a a été créée avec succès !"

