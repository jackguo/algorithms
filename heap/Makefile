CC = g++
FLAGS = -g -std=c++11
OBJS = MaxHeap.o

test: TestHeap.cpp
	$(CC) $(FLAGS) $^ -o $@
$(OBJS): MaxHeap.h
	$(CC) -c $(FLAGS) MaxHeap.h -o $@

clean:
	rm *.o test
