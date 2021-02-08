//	Tiffany Cai
//  FindPaths.cpp
//  


#include <stdio.h>
#include "CreateGraphAndTest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        cout << "Usage: " << argv[0] <<" <GRAPH_FILE> <STARTING_VERTEX>" << endl;
        return 0;
    }
    const string graph_(argv[1]);
    int starting_vertex_ = atoi(argv[2]);

    ifstream file(graph_);
    string line_;
    int num_ver_;
    file >> num_ver_;
    //cout <<"Number of vertices: "<< num_ver_ << endl;
    Graph new_graph (num_ver_);
    
    int vertex_;
    int adj_vertex_;
    double weight;
    while (getline(file, line_))
    {
        stringstream var_(line_);
        var_ >> vertex_;
        while (var_ >> adj_vertex_ && var_ >> weight)
        {
            new_graph.Insert(vertex_, adj_vertex_, weight);
        }
    }
    cout<<"still working: "<< starting_vertex_<<endl;
    new_graph.Dijkstra(starting_vertex_);

    return 0;
}
