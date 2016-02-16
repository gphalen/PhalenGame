a.out:	Program1.o Box.o World.o 
	g++ Program1.o Box.o World.o
program1.o:	Program1.cpp
	g++ -c Program1.cpp
world.o:	World.cpp dynamicList.h
	g++ -c World.cpp 
box.o:	box.cpp 
	g++ -c Box.cpp
clean:
	rm -f *.o a.out
