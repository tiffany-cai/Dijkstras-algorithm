# Dijkstras-algorithm

This program uses Dijkstra’s Algorithm to find the shortest paths from a given starting vertex to all vertices in the graph file.  It will read a text file (i.e. Graph1.txt) and convert it into an adjacency list which represents the graph. Then for each pair of vertices in AdjacenyQueries.txt, the program will print out whether the vertices are adjacent or not, and the weight of the edge that connects them if it exists.

To run in terminal,

make clean

make all

/CreateGraphAndTest Graph1.txt AdjacencyQueries.txt

Dijkstra's Algorithm is implemented using a priority queue. The program prints the paths to every destination. For example, it can run the program having as input Graph2.txt starting from vertex 1 as seen with the command below,

/FindPaths Graph2.txt 1
