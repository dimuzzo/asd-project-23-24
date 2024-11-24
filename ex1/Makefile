CC = gcc
CFLAGS = -I/.include -Wall -Wextra
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj

# File sorgente e oggetto di Unity. Il file oggetto viene creato dopo la compilazione
UNITY_SRC = $(SRC_DIR)/unity.c
UNITY_OBJ = $(OBJ_DIR)/unity.o

# Regola per la definizione dei parametri di esecuzione
set_records = $(SRC_DIR)/records.csv
sorted_records = $(SRC_DIR)/sorted.csv
field = 1
algo = 1

# Regola per creazione dei file
all: directories $(BIN_DIR)/main_ex1 $(BIN_DIR)/test_ex1

# Creazione directories necessarie
directories:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)
	
# Regola per compilare il file eseguibile main_ex1 e generarlo nella directory bin
$(BIN_DIR)/main_ex1: $(SRC_DIR)/mergesort_quicksort.c $(SRC_DIR)/sort_records.c
	$(CC) $(CCFLAGS) -o $@ $^

# Regola per compilare il file eseguibile test_ex1 e generarlo nella directory bin	
$(BIN_DIR)/test_ex1: $(SRC_DIR)/mergesort_quicksort.c $(SRC_DIR)/mergesort_quicksort_test.c $(UNITY_OBJ)
	$(CC) $(CCFLAGS) -o $@ $^

# Regola per compilare il file oggetto unity.o e generarlo nella directory obj
$(UNITY_OBJ): $(UNITY_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<
	
# Esecuzione del file main_ex1
runMain: $(BIN_DIR)/main_ex1
	time bin/main_ex1 $(set_records) $(sorted_records) $(field) $(algo)
	
# Esecuzione del file test_ex1
runTest: $(BIN_DIR)/test_ex1
	time bin/test_ex1

# Regola per la pulizia dei file compilati
clean:
	rm -f $(BIN_DIR)/main_ex1 $(BIN_DIR)/test_ex1 $(UNITY_OBJ)