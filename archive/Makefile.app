CC = gcc

CFLAGS = -Wall -Wextra -pedantic -std=c99

APP_NAME = app

SRC_FILES = app.c
OBJ_FILES = *.o

LIB_DIR = .
LIB_NAME = libapp_data.a

all: $(APP_NAME)

$(APP_NAME): $(OBJ_FILES) $(LIB_DIR)/$(LIB_NAME)
	@echo "Création de l'exécutable $(APP_NAME)"
	$(CC) $(CFLAGS) -o $(APP_NAME) $(OBJ_FILES) -L$(LIB_DIR) -lapp_data -ldrv_api

%.o: %.c
	@echo "Compilation de $<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Nettoyage des fichiers intermédiaires"
	rm -f $(OBJ_FILES) $(APP_NAME)

.PHONY: all clean
