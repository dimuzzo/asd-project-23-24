JAVAC = javac
JAVA = java
JUNIT_PATH = ./lib/junit-4.13.2.jar
HAMCREST_PATH = ./lib/hamcrest-core-1.3.jar
SRC_DIR = ./src
LIB_DIR = ./lib
BIN_DIR = ./bin
INP_DIR = ./inp

# Lista di tutti i file .java da compilare
SOURCES := $(wildcard $(SRC_DIR)/*.java)

# Lista file .class da generare
CLASSES = $(SOURCES:$(SRC_DIR)/%.java=$(BIN_DIR)/%.class)

# Opzioni compilatore java
JAVAC_FLAGS = -d $(BIN_DIR) -cp $(LIB_DIR)/*:$(BIN_DIR)

# Classi contenenti i main dei file da eseguire
MAIN_CLASS_PRIORITYQUEUE = PriorityQueue_Testing_Runner
MAIN_CLASS_GRAPH = Graph_Testing_Runner
MAIN_CLASS_EDGE = Edge_Testing_Runner
MAIN_CLASS_PRIM = Prim

# Regola per la compilazione totale codici
all: directories $(CLASSES)

# Creazione directories necessarie
directories:
	mkdir -p $(BIN_DIR)

# Compilazione file .java in file .class
$(BIN_DIR)/%.class: $(SRC_DIR)/%.java | $(BIN_DIR)
	$(JAVAC) $(JAVAC_FLAGS) $<

# Regola per l'esecuzione di PriorityQueue_Testing
runPriorityQueue: $(CLASSES)
	$(JAVA) -cp $(LIB_DIR)/*:$(BIN_DIR) $(MAIN_CLASS_PRIORITYQUEUE)

# Regola per l'esecuzione di Graph_Testing
runGraph: $(CLASSES)
	$(JAVA) -cp $(LIB_DIR)/*:$(BIN_DIR) $(MAIN_CLASS_GRAPH)

# Regola per l'esecuzione di Edge_Testing
runEdge: $(CLASSES)
	$(JAVA) -cp $(LIB_DIR)/*:$(BIN_DIR) $(MAIN_CLASS_EDGE)

# Regola per l'esecuzione di Prim
runPrim: $(CLASSES)
	$(JAVA) -cp $(LIB_DIR)/*:$(BIN_DIR) $(MAIN_CLASS_PRIM) $(INP_DIR)/italian_dist_graph.csv

# Regola per l'esecuzione dei test
test: $(CLASSES)
	$(JAVA) -cp $(LIB_DIR)/*:$(BIN_DIR):$(JUNIT_PATH):$(HAMCREST_PATH) org.junit.runner.JUnitCore $(TESTING_CLASSES)


# Regola per la pulizia dei file compilati
clean:
	rm -rf $(BIN_DIR)/*.class

# Utilizzo target phony per garantire l'esecuzione di ogni target
.PHONY: all runPriorityQueue runGraph runEdge runPrim test clean