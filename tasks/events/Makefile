all:
	gcc -c -g *.c -std=c99
	gcc *.o -o a.out -lprogbase
	rm *.o
	gnome-terminal --tab -e "/bin/bash -c 'valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all ./a.out; exec /bin/bash -i'"
