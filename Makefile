CXX = g++
CXXFLAGS = -std=c++17 -Wall -pthread -Iinclude

TARGET = sim_os
SRC = src/main.cpp src/Process.cpp src/Scheduler.cpp src/ResourceManager.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
