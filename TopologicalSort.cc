//	Tiffany Cai
//  TopologicalSort.cpp
//  


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "CreateGraphAndTest.h"
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] <<" <GRAPH_FILE> " << endl;
        return 0;
    }
    const string graph_(argv[1]);

    ifstream file(graph_);
    string line_;
    int num_ver_;
    file >> num_ver_;
   // cout <<"Number of vertices: "<< num_ver_ << endl;
    Graph new_graph (num_ver_);

    int vertex_;
    int adjacent_vertex_;
    double weight;
    while (getline(file, line_))
    {
        stringstream var_(line_);
        var_ >> vertex_;

        while (var_ >> adjacent_vertex_ && var_ >> weight)
        {
            new_graph.Insert(vertex_, adjacent_vertex_, weight);
        }
    }
    new_graph.TopologicalSort();
    return 0;
}
