run:
	make compile
	./prog

make try:
	make compile
	./prog testes/

compile:
	clear
	gcc -o prog *.c 

valgrind:
	make compile
	valgrind --leak-check=full ./prog