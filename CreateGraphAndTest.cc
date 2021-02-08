//	Tiffany Cai
//  CreateGraphAndTest.cpp
//  


#include "CreateGraphAndTest.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

//argument count, argument vector
int main(int argc, char **argv){
    if (argc!=3){//if 3 argument vectors not given, ask to reinput
        cout<<"Usage: " << argv[0] <<" <Graph> <AdjacencyQueries>" << endl;
        return 0;
    }
    //read second and third argument vectors
    const string graph_(argv[1]);
    const string adj_queries_(argv[2]);
    
    //read first file
    ifstream file(graph_);
    string line_;
    int num_vertices;
    file>>num_vertices;
   // cout<<"Number of vertices: "<< num_vertices << endl;
    Graph new_graph_(num_vertices);//create new graph with given number of vertices
    
    int vertex_;
    int adj_vertex_;
    double weight;
    while (getline(file,line_)) {
        stringstream var_(line_);
        var_ >> vertex_;
        while (var_ >> adj_vertex_ && var_ >> weight) {
            new_graph_.Insert(vertex_, adj_vertex_, weight);
        }
    }
    
    ifstream queries(adj_queries_);
    //string a_line_;
    while(getline(queries, line_)){
        //cout<<"still working 2" <<endl;
        stringstream var_(line_);
        while (var_>>vertex_ && var_>>adj_vertex_) {
            new_graph_.IsAdjacent(vertex_, adj_vertex_);
        }
    }
    return 0;
    
    
}
