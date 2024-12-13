# Directorios de origen y destino
SRC_DIR := src
BIN_DIR := bin

# Librerías necesarias de SFML y Box2D
SFML := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lbox2d

# Incluir encabezados del directorio 'include'
INCLUDE := -Iinclude

# Obtener todos los archivos .cpp en el directorio de origen
CPP_FILES := $(wildcard $(SRC_DIR)/*.cpp)

# Generar los nombres de los archivos .exe en el directorio de destino
EXE_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.exe,$(CPP_FILES))

# Regla principal para compilar cada archivo .cpp y generar el archivo .exe correspondiente
$(BIN_DIR)/%.exe: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR) # Crear el directorio bin si no existe
	g++ $< -o $@ $(SFML) $(INCLUDE) -Wall -std=c++17

# Regla por defecto para compilar todos los archivos .cpp
all: $(EXE_FILES)

# Regla para ejecutar cada archivo .exe
run%: $(BIN_DIR)/%.exe
	./$<

# Regla para limpiar los archivos generados
clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean run-%
