a.out:	main_s.o Server.o
	g++ -o ../../exe/a.out_server main_s.o Server.o

main_s.o:	main_s.cpp include/Server.h
	g++	-c main_s.cpp

Server.o:	src/Server.cpp src/Server.cpp
	g++ -c src/Server.cpp

clean:
	rm -f *.o
