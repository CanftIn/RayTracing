CC = g++

OBJ = ./main.o

COMMONFLAGS = -Wall -Wextra -O2 -g
CXXFLAGS = $(COMMONFLAGS) -std=c++11

INC = -I "./"

TARGET = ./RayTracing.exe

RayTracing: $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)
	rm -f $(OBJ)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< $(INC)

clean:
	rm -f $(OBJ) RayTracing