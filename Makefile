# Variables
CXX = g++
CXXFLAGS = -Iinclude -Wall
LDFLAGS = -lncurses

# Directorios
SRC_DIR = src
BIN_DIR = bin
INC_DIR = include

# Archivos de fuente
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)
TARGET = $(BIN_DIR)/breakout

# Reglas
all: create_dirs $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

create_dirs:
	mkdir -p $(BIN_DIR)

run: all
	./$(TARGET)

clean:
	rm -f $(BIN_DIR)/*.o $(TARGET)
