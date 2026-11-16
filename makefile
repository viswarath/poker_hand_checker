poker_hand_checker: poker_hand_checker.o poker_hand_funcs.o
	cc -o poker_hand_checker poker_hand_checker.o poker_hand_funcs.o

poker_hand_funcs.o: poker_hand_funcs.c
	cc -c poker_hand_funcs.c -W -Wall -O

# to test, run makefile test
test: poker_hand_tester.o poker_hand_funcs.o
	cc -o test poker_hand_tester.o poker_hand_funcs.o

poker_hand_tester.o: poker_hand_tester.c
	cc -c poker_hand_tester.c -W -Wall -O

all: test poker_hand_checker

clean:
	rm -f poker_hand_funcs.o poker_hand_checker.o poker_hand_checker poker_hand_tester.o test 
