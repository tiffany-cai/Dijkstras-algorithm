########################################
##
## Makefile
## LINUX compilation 
##
##############################################





#FLAGS
C++FLAG = -g -std=c++11 -Wall

#Math Library
MATH_LIBS = -lm
EXEC_DIR=.



#Rule for .cc files
# .SUFFIXES : .cc.o 

.cc.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@


#Including
INCLUDES=  -I. 


LIBS_ALL =  -L/usr/lib -L/usr/local/lib $(MATH_LIBS) 


#ZEROTH PROGRAM
ALL_OBJ0=CreateGraphAndTest.o
PROGRAM_0=CreateGraphAndTest
$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

#First Program
ALL_OBJ1=FindPaths.o
PROGRAM_1=FindPaths
$(PROGRAM_1): $(ALL_OBJ1)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)

#Second Program
ALL_OBJ2=TopologicalSort.o
PROGRAM_2=TopologicalSort
$(PROGRAM_2): $(ALL_OBJ2)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ2) $(INCLUDES) $(LIBS_ALL)

#Compiling all

all: 	
		make $(PROGRAM_0)
		make $(PROGRAM_1)
		make $(PROGRAM_2)

rungraph1: 	
		./$(PROGRAM_0) Graph1.txt AdjacencyQueries1.txt

rungraph3: 	
		./$(PROGRAM_0) Graph3.txt AdjacencyQueries3.txt

runtopo:
		./$(PROGRAM_1) Graph3.txt

rundij:
		./$(PROGRAM_2) Graph2.txt 1


#Clean obj files

clean:
	(rm -f *.o; rm -f $(PROGRAM_0))
	(rm -f *.o; rm -f $(PROGRAM_1))
	(rm -f *.o; rm -f $(PROGRAM_2))



(:
