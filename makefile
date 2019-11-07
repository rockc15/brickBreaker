brick: brickbreaker.o
	gcc brickbreaker.o -o brick -lsense -lm
brickbreaker.o: brickbreaker.c
	gcc -c brickbreaker.c -lsense -lm
