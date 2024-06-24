# Configuración de variables
CC = g++
CFLAGS = -Iinclude -Wall
LDFLAGS = -lncurses
TARGET = breakout
SRCDIR = src
OBJDIR = build

# Lista de archivos fuente y objetos
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Regla para compilar todos los objetos
all: $(TARGET)

# Regla para el objetivo final
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDFLAGS) -o $@

# Regla para compilar cada archivo fuente
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para crear directorio de objetos si no existe
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regla para limpiar archivos temporales
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)

# Regla para ejecutar el juego
run:
	./$(TARGET)

# Phony targets (no son archivos reales)
.PHONY: all clean run
