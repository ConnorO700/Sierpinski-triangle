all: main.o Sierpinski.o main2.o Circ.o
	g++ main.o Sierpinski.o -o Sierpinski -lsfml-graphics -lsfml-window -lsfml-system
	g++ main2.o Circ.o -o original -lsfml-graphics -lsfml-window -lsfml-system 

main.o: main.cpp
	g++ -c main.cpp -Wall -Werror -ansi -pedantic 

Sierpinski.o: Sierpinski.cpp Sierpinski.hpp
	g++ -c Sierpinski.cpp -Wall -Werror -ansi -pedantic 

main2.o: main2.cpp
	g++ -c main2.cpp -Wall -Werror -ansi -pedantic 

Circ.o:Circ.cpp Circ.hpp
	g++ -c Circ.cpp -Wall -Werror -ansi -pedantic

clean: 
	rm *.o Sierpinski original
