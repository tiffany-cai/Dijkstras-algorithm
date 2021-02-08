//	Tiffany Cai
//  Vertex.hpp
//  


#ifndef Vertex_hpp
#define Vertex_hpp

#include <stdio.h>
#include <queue>
#include <limits>


struct AdjVertex{
    int num_ver_;
    double weight_;

    AdjVertex (const int & vertices, const double & weight) : num_ver_ {vertices}, weight_{weight}{}
};

struct Vertex{
    int vertex_num_;
    bool known;
    double distance_;
    int indegree_;
    int topsort_;
    Vertex *path_;
    
    std::vector <AdjVertex> adj_vertices_;
    
    Vertex (const int & num_ver_, const bool & known, const double & dist_, const int indegree, const int topsort, Vertex * path)
    : vertex_num_ {num_ver_}, known{known}, distance_ {dist_}, indegree_ {indegree}, topsort_{topsort}, path_ {path} {}
    
};

struct Comparison
{
    bool operator() (const Vertex * v1, const Vertex * v2) const
    {
        return v1 -> distance_ > v2 -> distance_;
    }
};

#endif /* Vertex_hpp */
