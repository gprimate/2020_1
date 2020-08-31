#	Name	of	the	project
PROJ_NAME=./tp1
TMPOUT=tp1.testresult
	
#	.c	files
CPP_SOURCE=$(wildcard	*.cpp)	$(wildcard	*/*.cpp)	
#	.h	files
H_SOURCE=$(wildcard	*.h)	$(wildcard	*/*.h)
	
#	Object	files
OBJ=$(CPP_SOURCE:.cpp=.o)
	
#	Compiler
CC=g++
	
#	Flags	for	compiler
CC_FLAGS=-c	-std=c++11
	
#
#	Compilation	and	linking
#
all:	$(PROJ_NAME)
	
test:	$(PROJ_NAME)
	@bash	../run_tests.sh	$(PROJ_NAME)	$(TMPOUT)

$(PROJ_NAME):	$(OBJ)
	$(CC)	-o	$@	$^
	
%.o:	%.cpp	%.h
	
	$(CC)	-o	$@	$<	$(CC_FLAGS)
	
main.o:	main.cpp	$(H_SOURCE)
	$(CC)	-o	$@	$<	$(CC_FLAGS)
	
clean:
	rm	-rf	*.o	$(PROJ_NAME)	*~	
