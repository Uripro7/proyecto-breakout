CXX = g++
CXXFLAGS = -Iinclude -lncurses -Wall -std=c++11

SOURCES = src/main.cpp src/Game.cpp src/Ball.cpp src/Paddle.cpp src/Brick.cpp src/Life.cpp src/ScreenManager.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = breakout

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(CXXFLAGS)

clean:
	rm -f src/*.o $(EXECUTABLE)

run: all
	./$(EXECUTABLE)
