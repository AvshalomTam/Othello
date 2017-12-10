a.out:	main_s.o Server.o
	g++ -o a.out_server main_s.o Server.o

main_s.o:	main_s.cpp include/Server.h
	g++	-c main_s.cpp

Server.o:	src/Server.cpp src/Server.cpp
	g++ -c src/Server.cpp

run:
	./a.out_server

clean:
	rm -f *.o a.out
