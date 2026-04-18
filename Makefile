CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = ttt

SRC = src/main.cpp src/game.cpp src/ai.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)
