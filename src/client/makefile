a.out:  compile
	g++ -pthread -o a.out_client *.o
	rm -f *.o

compile:	*.cpp include/*.h src/*.cpp
	g++ -pthread -c *.cpp src/*.cpp

memory:
	valgrind ./a.out_client

full_memory:
	valgrind --leak-check=full ./a.out_client
