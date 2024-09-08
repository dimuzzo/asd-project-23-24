CC = gcc
CFLAGS = -I/.include -Wall -Wextra
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj

# File sorgente e oggetto di Unity. Il file oggetto viene creato dopo la compilazione
UNITY_SRC = $(SRC_DIR)/unity.c
UNITY_OBJ = $(OBJ_DIR)/unity.o

# Regola per creazione dei file
all: directories $(BIN_DIR)/main_ex2 $(BIN_DIR)/test_ex2

# Creazione directories necessarie
directories:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)

# Regola per compilare il file eseguibile main_ex2 e generarlo nella directory bin
$(BIN_DIR)/main_ex2: $(SRC_DIR)/main_test.c $(SRC_DIR)/edit_distance.c
	$(CC) $(CCFLAGS) -o $@ $^

# Regola per compilare il file eseguibile test_ex2 e generarlo nella directory bin	
$(BIN_DIR)/test_ex2: $(SRC_DIR)/edit_distance_test.c $(SRC_DIR)/edit_distance.c $(UNITY_OBJ)
	$(CC) $(CCFLAGS) -o $@ $^
	
# Regola per compilare il file oggetto unity.o e generarlo nella directory obj
$(UNITY_OBJ): $(UNITY_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

# Regola per la pulizia dei file compilati
clean:
	rm -f $(BIN_DIR)/main_ex2 $(BIN_DIR)/test_ex2 $(UNITY_OBJ)
