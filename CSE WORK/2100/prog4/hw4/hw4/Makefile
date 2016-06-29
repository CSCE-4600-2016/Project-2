# makefile for program 4
# Yosvany Blanco
# written for group G
# csce 2100
# simply type make run to compile and run
# or type make to just compile

# standard make file with dependencies intact

book: G_00_P4_main.o G_00_P4_functions.o
	g++ -o book G_00_P4_main.o G_00_P4_functions.o

G_00_P4_main.o: G_00_P4_main.cpp G_00_P4_main.h 
	g++ -c G_00_P4_main.cpp

G_00_P4_functions.o: G_00_P4_functions.cpp G_00_P4_main.h
	g++ -c G_00_P4_functions.cpp

run: book
	./book

# will throw error if bookdebug doesn't exist
# don't worry does not affect the clean at all still cleans
# object files and book
clean:
	rm *.o book bookdebug
 
# debug cmd just to quickly compile with the -g flag and run gdb with executable 
# no dependencies checked here
debug: 
	g++ -o bookdebug G_00_P4_main.cpp G_00_P4_functions.cpp -g; gdb bookdebug

