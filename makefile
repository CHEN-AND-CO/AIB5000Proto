CFLAGS = -g -Wall -pedantic -std=c++17

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = $(wildcard src/*.cpp)
NOM = $(basename $(notdir $(SRC)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(NOM)))
UNITOBJ = 

all: AIB.out

remake: clean AIB.out

AIB.out : $(OBJ)
	g++ obj/* $(LDFLAGS) -o $@ 

obj/%.o: src/%.cpp
	g++ -c $< -Iinclude -o $@ $(CFLAGS)

clean:
	rm obj/*.o *.out *.gch -f

clear:
	rm obj/*.o *.gch -f

