OBJS = vector.o sort.o
CFLAGS = -Wall -g

all: $(OBJS) 
	gcc $(CFLAGS) -o sort $(OBJS)

vector.o: vector.c vector.h
	gcc $(CFLAGS) -c vector.c vector.h 

main.o: sort.c vector.h
	gcc $(CFLAGS) -c sort.c vector.h

.PHONY: test
test:
	./sort test/testNewLine.txt
	./sort test/testDanishLetters.txt
	./sort test/test.txt

.PHONY: clean
clean:
	rm -f *.o sort vector.h.gch output.txt
