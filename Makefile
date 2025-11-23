CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra

SRC = src/Token.cpp src/Lexer.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)
