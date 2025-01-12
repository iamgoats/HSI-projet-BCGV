# Nom du compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -pedantic -std=c99

# Nom de l'exécutable généré
APP_NAME = app

# Fichiers sources
SRC_FILES = app.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Chemin vers la librairie statique
LIB_DIR = .
LIB_NAME = libapp_data.a

# Cible principale
all: $(APP_NAME)

# Génération de l'exécutable
$(APP_NAME): $(OBJ_FILES) $(LIB_DIR)/$(LIB_NAME)
	@echo "Création de l'exécutable $(APP_NAME)"
	$(CC) $(CFLAGS) -o $(APP_NAME) $(OBJ_FILES) -L$(LIB_DIR) -lapp_data -ldrv_api

# Compilation des fichiers objets
%.o: %.c
	@echo "Compilation de $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers générés
clean:
	@echo "Nettoyage des fichiers intermédiaires"
	rm -f $(OBJ_FILES) $(APP_NAME)

# Indiquer que certaines cibles ne sont pas des fichiers
.PHONY: all clean
