# disclaimers: precisa mudar o argv se o nome da pasta mudar

# compila e executa o programa
run:
	make compile
	./prog Entradas/

# limpa o terminal e compila
compile:
	clear
	gcc -o prog *.c 

# compila e executa o valgrind
valgrind:
	make compile
	valgrind --leak-check=full -s ./prog Entradas/