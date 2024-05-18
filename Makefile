# compila e executa o programa
run:
	make compile
	./prog

# apenas executa o arquivo prog.exe
exe:
	clear.
	./prog

# limpa o terminal e compila
compile:
	clear
	gcc -o prog *.c 

# compila e executa o valgrind
valgrind:
	make compile
	valgrind --leak-check=full -s --track-origins=yes  ./prog