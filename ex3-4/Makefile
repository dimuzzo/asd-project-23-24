JAVAC = javac
JAVA = java
JUNIT_PATH = lib/junit-4.13.2.jar
HAMCREST_PATH = lib/hamcrest-core-1.3.jar
SRC_DIR = src
LIB_DIR = lib
BIN_DIR = bin

# Lista di tutti i file .java da compilare
SOURCES = $(wildcard $(SRC_DIR)/*.java)

# Lista file .class da generare
CLASSES = $(SOURCES:$(SRC_DIR)/%.java=$(BIN_DIR)/%.class)

# Opzioni compilatore java
JAVAC_FLAGS = -d $(BIN_DIR) -cp $(LIB_DIR)/*:$(BIN_DIR)

# Classi contenenti i main dei file da eseguire
MAIN_CLASS_PRIORITYQUEUE = PriorityQueue_Runner

# Regola per la compilazione totale codici
all: directories $(CLASSES)

# Creazione directories necessarie
directories:
	mkdir -p $(BIN_DIR)

# Compilazione file .java in file .class
$(BIN_DIR)/%.class: $(SRC_DIR)/%.java | $(BIN_DIR)
	$(JAVAC) $(JAVAC_FLAGS) $<

# Regola per l'esecuzione dei test
test: all
	$(JAVA) -cp $(LIB_DIR)/*:$(BIN_DIR):$(JUNIT_PATH):$(HAMCREST_PATH) org.junit.runner.JUnitCore $(TESTING_CLASSES)


# Regola per la pulizia dei file compilati
clean:
	rm -rf $(BIN_DIR)/*.class