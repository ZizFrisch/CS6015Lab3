#Elisabeth Frischknecht
#January 11, 2024
#Makefile for HW1 - CS6015

#MACROS

CXX = c++
#should specify the C++ type here? ask a TA
CFLAGS = -std=c++11
CXXSOURCE = cmdline.cpp main.cpp expr.cpp tests.cpp
HEADERS = cmdline.hpp expr.hpp
CCOMPILE = -c
CLINK = -o

#myProgram is the executable that will be created. It will use the .o targets as prerequisites
msdscript: cmdline.o main.o expr.o tests.o
	$(CXX) $(CFLAGS) *.o $(CLINK) msdscript
	
#build: this builds the executable, and since myProgram is the prerequisite it will only compile the necessary files
build: msdscript

#each .o file target will create the .o file of a given .cpp and .h file.
cmdline.o: cmdline.cpp cmdline.hpp
	$(CXX) $(CFLAGS) $(CCOMPILE) cmdline.cpp
	
main.o: main.cpp
	$(CXX) $(CFLAGS) $(CCOMPILE) main.cpp
	
expr.o: expr.cpp expr.hpp
	$(CXX) $(CFLAGS) $(CCOMPILE) expr.cpp
	
tests.o: tests.cpp
	$(CXX) $(CFLAGS) $(CCOMPILE) tests.cpp
	


#clean will remove all the files created by this make file, including the executable
clean:
	rm *.o msdscript

#run: this will run the program, with the prerequisite of building it
run: build
	./msdscript
	
test: build
	./msdscript --test

#this tells make that these targets are not associated with files
.PHONY: clean run printM build test

#printM will print the values of the Macros that I created
printM:
	echo CXX $(CXX)
#	echo CFLAGS
	echo CXXSOURCE $(CXXSOURCE)
	echo HEADERS $(HEADERS)
	echo CCOMPILE $(CCOMPILE)
	echo CLINK $(CLINK)

