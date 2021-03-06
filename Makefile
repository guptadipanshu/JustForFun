EXE = main
OBJS = Trees.o  main.o
COMPILER = g++
COMPILER_OPTS = -c -g -O0 -Wall -Werror
LINKER = g++

all : main 

$(EXE) : $(OBJS)
	$(LINKER) $(OBJS) $(LINKER_OPTS) -o $(EXE)

main.o : main.cpp Trees.h 
	$(COMPILER) $(COMPILER_OPTS) main.cpp


Trees.o : Trees.h Trees.cpp
	$(COMPILER) $(COMPILER_OPTS) Trees.cpp
	
clean :
	-rm -f *.o $(EXE) 
