a.out:	main_s.o Server.o
	g++ main_s.o Server.o

main_s.o:	main_s.cpp Server.h
	g++	-c main_s.cpp

Server.o:	Server.cpp Server.cpp
	g++ -c Server.cpp

run:
	./a.out

clean:
	rm -f *.o a.out
