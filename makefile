CC = gcc
AR = ar 
 CFLAGS = -Wall -g
 LFLAGS = -shared
 SFLAGS = rcs
 FP = -fPIC
 # File names
GRAPH = my_graph.c
HEADER = my_mat.h
SRC = my_mat.c
PARTWO = my_Knapsnap.c


.PHONY: all clean 
# Build everything 
all: my_graph my_Knapsnap

my_graph: my_graph.o my_mat.o
	$(CC) my_graph.o my_mat.o -o my_graph 
my_Knapsnap: my_Knapsnap.o my_mat.o
	$(CC) my_Knapsnap.o -o my_Knapsnap
my_Knapsnap.o: $(PARTWO)$(HEADER)  
	$(CC) $(CFLAGS) -c $(PARTWO)
	
my_graph.o: $(GRAPH) $(HEADER)  
	$(CC) $(CFLAGS) -c my_graph.c

my_mat.o: $(SRC) $(HEADER)
	$(CC) $(CFLAGS) -c $(SRC)

	# Clean command to cleanup all the compiled files (*.o, *.a, *.so, *.gch)
clean:
	rm -f   *.o *.a *.so *.gch