CC = gcc
CFLAGS = -I/.include -Wall -Wextra
SRC_DIR = src
BIN_DIR = bin

all: $(BIN_DIR)/main_ex2 $(BIN_DIR)/test_ex2
     $(BIN_DIR)/main_ex2: $(SRC_DIR)/.c $(SRC_DIR)/edit_distance.c
                          $(CC) $(CCFLAGS) -o $@ $^
     $(BIN_DIR)/test_ex2: $(SRC_DIR)/edit_distance_test.c $(SRC_DIR)/edit_distance.c
                          $(CC) $(CCFLAGS) -o $@ $^

clean:
	rm -f $(BIN_DIR)/main_ex2 $(BIN_DIR)/test_ex2