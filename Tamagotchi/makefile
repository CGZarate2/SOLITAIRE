# Directorios de origen y destino
SRC_DIR := src
BIN_DIR := bin

# Archivos específicos
MAIN_SRC := $(SRC_DIR)/main.cpp
KIRBY_SRC := $(SRC_DIR)/Kirby.cpp
MAIN_EXE := $(BIN_DIR)/main.exe

# Librerías SFML
SFML := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Compilador y flags
CXX := g++
CXXFLAGS := -Iinclude

# Regla por defecto para compilar main.exe
all: $(MAIN_EXE)

# Compilar main.exe con sus dependencias
$(MAIN_EXE): $(MAIN_SRC) $(KIRBY_SRC)
	$(CXX) $^ -o $@ $(CXXFLAGS) $(SFML)

# Regla para ejecutar el programa
runmain: $(MAIN_EXE)
	./$(MAIN_EXE)

# Limpiar binarios generados
clean:
	rm -f $(MAIN_EXE)

.PHONY: all clean runmain
