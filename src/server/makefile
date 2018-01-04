a.out:  compile
	g++ -pthread -o a.out_server *.o
	rm -f *.o

compile:	*.cpp include/*.h src/*.cpp
	g++ -pthread -c *.cpp src/*.cpp

memory:
	valgrind ../../exe/a.out_server

full_memory:
	valgrind --leak-check=full ../../exe/a.out_server
