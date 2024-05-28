CC = gcc
CFLAGS = -I/.include -Wall -Wextra
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj

UNITY_SRC = $(SRC_DIR)/unity.c
UNITY_OBJ = $(OBJ_DIR)/unity.o

all: $(BIN_DIR)/main_ex2 $(BIN_DIR)/test_ex2

$(BIN_DIR)/main_ex2: $(SRC_DIR)/main_test.c $(SRC_DIR)/edit_distance.c
	$(CC) $(CCFLAGS) -o $@ $^
	
$(BIN_DIR)/test_ex2: $(SRC_DIR)/edit_distance_test.c $(SRC_DIR)/edit_distance.c $(UNITY_OBJ)
	$(CC) $(CCFLAGS) -o $@ $^
	
$(UNITY_OBJ): $(UNITY_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(BIN_DIR)/main_ex2 $(BIN_DIR)/test_ex2 $(UNITY_OBJ)
