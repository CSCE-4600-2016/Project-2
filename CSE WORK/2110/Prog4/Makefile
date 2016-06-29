# Yosvany Blanco Makefile
# Program 2 - 4
# simply type make run to compile and run
# or type make to just compile

graph: F_10_P4_main.o F_10_P4_tools.o
	g++ -std=c++0x F_10_P4_main.o F_10_P4_tools.o -o graph

F_10_P4_main.o: F_10_P4_main.cpp F_10_P4_tools.h
	g++ -std=c++0x -c F_10_P4_main.cpp

F_10_P4_tools.o: F_10_P4_tools.cpp F_10_P4_tools.h
	g++ -std=c++0x -c F_10_P4_tools.cpp
	
run: graph
	./graph
	
debug:
	g++ -std=c++0x F_10_P4_main.cpp F_10_P4_tools.cpp -g; gdb a.out

#will delete any exist object files and will delete the 
#executable
clean:
	rm *.o graph 
