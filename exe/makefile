server:
	make -f ./makefile.ser
client:
	make -f makefile.cli
run_server:
	./a.out_server
run_client:
	./a.out_client
memory_server:
	valgrind --leak-check=full ./a.out_server
memory_client:
	valgrind --leak-check=full ./a.out_client
