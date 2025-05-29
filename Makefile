# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 `sdl2-config --cflags` -Isrc

# SDL2 and SDL_ttf libraries
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf

# Output binary
TARGET = lissajous

# Source and object files
SRCDIR = src
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Build rule
$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compile source files into object files
$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(SRCDIR)/*.o $(TARGET)

