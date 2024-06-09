# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++2a -Wall -IController/Inc -IModel/Inc -IView/Inc -I./ $(shell sdl2-config --cflags)

# Linker flags
LDFLAGS = $(shell sdl2-config --libs) -lSDL2_mixer -lSDL2 -ltag -lz -lpthread -ludev

# Directories
CONTROLLER_DIR = Controller/Src
MODEL_DIR = Model/Src
VIEW_DIR = View/Src
OUTPUT_DIR = Output

# Source files
CONTROLLER_SOURCES = $(wildcard $(CONTROLLER_DIR)/*.cpp)
MODEL_SOURCES = $(wildcard $(MODEL_DIR)/*.cpp)
VIEW_SOURCES = $(wildcard $(VIEW_DIR)/*.cpp)
MAIN_SOURCE = main.cpp
SOURCES = $(CONTROLLER_SOURCES) $(MODEL_SOURCES) $(VIEW_SOURCES) $(MAIN_SOURCE) 

# Object files
OBJECTS = $(patsubst %.cpp, $(OUTPUT_DIR)/%.o, $(notdir $(SOURCES)))

# Executable
EXECUTABLE = run

# Default target
all: $(EXECUTABLE)

# Linking
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Compiling
$(OUTPUT_DIR)/%.o: $(CONTROLLER_DIR)/%.cpp | $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OUTPUT_DIR)/%.o: $(MODEL_DIR)/%.cpp | $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OUTPUT_DIR)/%.o: $(VIEW_DIR)/%.cpp | $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OUTPUT_DIR)/%.o: %.cpp | $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure output directory exists
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Clean
clean:
	rm -f $(OUTPUT_DIR)/*.o $(EXECUTABLE)

# PHONY targets
.PHONY: all clean
