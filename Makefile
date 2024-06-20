CXX = g++
CXXFLAGS = -Iinclude -I"C:\SFML-2.5.1\include" -Wall -std=c++11
LDFLAGS = -L"C:\SFML-2.5.1\lib" -lsfml-graphics -lsfml-window -lsfml-system
SRC = src/main.cpp src/Game.cpp src/Ball.cpp src/Paddle.cpp src/Brick.cpp
OBJ = $(SRC:.cpp=.o)
BIN = breakout

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)

run: all
	./$(BIN)
