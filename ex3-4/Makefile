JAVAC = javac
JAVA = java
LIB_DIR = lib
SRC_DIR = src
BIN_DIR = bin
INP_DIR = inp

# Percorsi delle librerie JUnit e Hamcrest
JUNIT_PATH = $(LIB_DIR)/junit-4.13.2.jar
HAMCREST_PATH = $(LIB_DIR)/hamcrest-core-1.3.jar

# Opzioni per la compilazione e l'esecuzione
JAVAC_FLAGS = -d $(BIN_DIR) -cp $(LIB_DIR)/*:$(BIN_DIR)
JAVA_FLAGS = -cp $(LIB_DIR)/*:$(BIN_DIR)

# Trova tutti i file .java in SRC_DIR, escludendo la dipendenza d'ordine per Prim
COMPILE_ORDER = $(filter-out $(SRC_DIR)/Prim.java, $(wildcard $(SRC_DIR)/*.java)) $(SRC_DIR)/Prim.java

# File .class corrispondenti in BIN_DIR
CLASS_FILES = $(patsubst $(SRC_DIR)/%.java,$(BIN_DIR)/%.class,$(COMPILE_ORDER))

# Classi per i test
TESTING_CLASSES = PriorityQueue_Testing Graph_Testing Edge_Testing

# Obiettivo predefinito: compila tutto
all: directories $(CLASS_FILES)

# Crea le directory necessarie
directories:
	mkdir -p $(BIN_DIR)

# Compila i file sorgente Java in file di classe
$(BIN_DIR)/%.class: $(SRC_DIR)/%.java | directories
	$(JAVAC) $(JAVAC_FLAGS) $<

# Esegui le classi principali specifiche
runPQ: $(CLASS_FILES)
	$(JAVA) $(JAVA_FLAGS) PriorityQueue_Testing_Runner

runGraph: $(CLASS_FILES)
	$(JAVA) $(JAVA_FLAGS) Graph_Testing_Runner

runEdge: $(CLASS_FILES)
	$(JAVA) $(JAVA_FLAGS) Edge_Testing_Runner

runPrim: $(CLASS_FILES)
	$(JAVA) $(JAVA_FLAGS) Prim $(INP_DIR)/italian_dist_graph.csv

# Esegui tutti i test unitari
test: $(CLASS_FILES)
	$(JAVA) -cp $(BIN_DIR):$(JUNIT_PATH):$(HAMCREST_PATH) org.junit.runner.JUnitCore $(TESTING_CLASSES)

# Pulisci i file compilati
clean:
	rm -rf $(BIN_DIR)/*.class