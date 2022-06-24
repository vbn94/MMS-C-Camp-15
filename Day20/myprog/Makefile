CC=clang

# this is comment
.PHONY: all
all: calc

# calculator program
calc: main.o mymath.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $<

.PHONY: clean
clean:
	rm *.o calc
