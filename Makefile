all: main

scc: scc.c
	gcc -o scc scc.c

test.s: scc
	./scc 42 > test.s

main: test.s
	gcc -o main test.s

run: main
	./main; echo $$?

clean:
	rm -f scc test.s main