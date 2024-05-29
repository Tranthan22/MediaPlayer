# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall -IController/Inc -IModel/Inc -IView/Inc $(shell sdl2-config --cflags)
# Linker flags
LDFLAGS = $(shell sdl2-config --libs) -lSDL2_mixer -lSDL2
# Directories
CONTROLLER_DIR = Controller/Src
MODEL_DIR = Model/Src
VIEW_DIR = View/Src
# Source files
CONTROLLER_SOURCES = $(wildcard $(CONTROLLER_DIR)/*.cpp)
MODEL_SOURCES = $(wildcard $(MODEL_DIR)/*.cpp)
VIEW_SOURCES = $(wildcard $(VIEW_DIR)/*.cpp)
MAIN_SOURCE = main.cpp
SOURCES = $(CONTROLLER_SOURCES) $(MODEL_SOURCES) $(VIEW_SOURCES) $(MAIN_SOURCE)
# Object files
OBJECTS = $(SOURCES:.cpp=.o)
# Executable
EXECUTABLE = run

# Default target
all: $(EXECUTABLE)

# Linking
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Compiling
Controller/Src/%.o: Controller/Src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Model/Src/%.o: Model/Src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

View/Src/%.o: View/Src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# PHONY targets
.PHONY: all clean


