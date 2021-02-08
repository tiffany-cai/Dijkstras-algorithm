//  Program should use Dijkstra’s Algorithm to find the shortest paths from a given starting vertex to all vertices in the graph file.
//  CreateGraphAndTest.hpp
//  
//
//  Created by Maisa Ahmad on 12/6/19.
//

#ifndef CreateGraphAndTest_hpp
#define CreateGraphAndTest_hpp

#include <stdio.h>
#include <iostream>
#include "Vertex.h"
#include <queue>
#include <limits>
using namespace std;


class Graph{
public:
    Graph(){}
    
    ~Graph(){
        MakeClear();
    }
    
    // Copy-constructor.
    Graph(const Graph &rhs) : vertices_(rhs.vertices_.size()){

        for (size_t i=1; i < rhs.vertices_.size(); i++){//go through items of rhs
            vertices_[i] = new Vertex(rhs.vertices_[i] -> vertex_num_, rhs.vertices_[i] -> known,
            rhs.vertices_[i] -> distance_, rhs.vertices_[i] -> indegree_, rhs.vertices_[i] -> topsort_, rhs.vertices_[i] -> path_);
            this->vertices_[i]->adj_vertices_ = rhs.vertices_[i]->adj_vertices_;
        }
    }
    
    // Copy-assignment.
    Graph& operator=(const Graph &rhs){
        Graph copy = rhs;
        std::swap(*this, copy);
        return *this;
    }
    
    // Copy-assignment.
    Graph(const int & num_vertices) : vertices_ (num_vertices + 1)
    {
        size_t inf = std::numeric_limits<int>::max();
        for (size_t i = 1; i < num_vertices + 1; i++)
        {
            vertices_[i] = new Vertex(i, false, inf, 0, 0, nullptr);
        }
    }
    
    //Function inserts adjacent vertices and weights to respective vertex
    void Insert(const int & ver_, const int & adj_ver, const double & weight_)
    {
        AdjVertex adj_ (adj_ver, weight_);
        vertices_[ver_] -> adj_vertices_.push_back (adj_);
    }
    
    //Function checks is two vertices are adjacent to one another
    void IsAdjacent(const int & v1, const int & v2)
    {
        bool check = false;
        for (size_t i = 0; i < vertices_[v1] -> adj_vertices_.size(); i++)
        {
            if (vertices_[v1] -> adj_vertices_[i].num_ver_ == v2)
            {
                check = true;
                std::cout << v1 <<" "<< v2 <<": Connected, weight of edge is " << vertices_[v1] -> adj_vertices_[i].weight_ << std::endl;
                break;
            }
        }
        if (!check)
            std::cout << v1 <<" "<< v2 <<": Not Connected " << std::endl;
    }
    
    void Dijkstra(const int & vertex)
    {
        vertices_[vertex] -> distance_ = 0;
        std::priority_queue <Vertex*, std::vector<Vertex*>, Comparison> min_priority_queue;
        min_priority_queue.push(vertices_[vertex]);

        while (!(min_priority_queue.empty()))
        {
            Vertex* vertex = min_priority_queue.top();
            min_priority_queue.pop();
            vertex -> known = true;

            for (int i = 0; i < vertex -> adj_vertices_.size(); i++)
            {
                int num_ver_ = vertex -> adj_vertices_[i].num_ver_;
                Vertex* find_ = vertices_[num_ver_];
                if (!find_ -> known)
                {
                    double weight = vertex -> adj_vertices_[i].weight_;
                    if (vertex -> distance_ + weight < find_ -> distance_)
                    {
                        find_ -> distance_ = vertex -> distance_ + weight;
                        find_ -> path_ = vertex;
                    }
                    min_priority_queue.push (find_);
                }
            }
        }

        for (size_t i = 1; i < vertices_.size(); i++)
        {
            std::cout << vertices_[i] -> vertex_num_ <<": ";
            double shortest_weight = vertices_[i] -> distance_;
            ShortestPaths(vertices_[i]);
            
            //if path found print cost, otherwise no path from starting vertex
            if (shortest_weight != std::numeric_limits<int>::max())
                std::cout << "(Cost: " << shortest_weight << ")" << std::endl;
            else
                std::cout << "(No path)" << std::endl;
        }
        
    }
    
    void TopologicalSort()
    {
        NumIndegrees();
        TopSort();
    }
    
    
private:
    //int num;
    //vector<Vertex, double> vertices_;
    vector<Vertex*> vertices_;
    
    void MakeClear()
    {
        for (size_t i = 1; i < vertices_.size(); i++)
        {
            delete vertices_[i];
            vertices_[i] = nullptr;
        }
    }
    
    //Counts the number of indegrees
    void NumIndegrees()
    {
        for (size_t i = 1; i < vertices_.size(); i++)//traverse through vertices
        {
            for (size_t j = 0; j < vertices_[i] -> adj_vertices_.size(); j++)
            {
                int adj_v_num = vertices_[i] -> adj_vertices_[j].num_ver_;
                vertices_[adj_v_num] -> indegree_++;  //count number of indegrees as traverse through adjacent vertices
            }
        }
    }

    //Finds the shortest path from given starting vertex
    void ShortestPaths (Vertex * v)
    {
        if (v -> path_ !=  nullptr)
        {
            ShortestPaths( v -> path_);
        }
        std::cout << v -> vertex_num_ << " ";
    }

    //Implements the topological sorting algorithm
    void TopSort()
    {
        std::queue <Vertex*> a_queue;
        int count = 0;

        for (size_t i = 1; i < vertices_.size(); i++)
        {
            if (vertices_[i] -> indegree_ == 0)
                a_queue.push(vertices_[i]);
        }

        while (!a_queue.empty())
        {
            Vertex* vertex_ = a_queue.front();
            std::cout << vertex_ -> vertex_num_;
            a_queue.pop();
            vertex_ -> topsort_ = ++count;
            for (int j = 0; j < vertex_ -> adj_vertices_.size(); j++)
            {
                Vertex* w = vertices_[vertex_ ->adj_vertices_[j]. num_ver_];
                w -> indegree_--;
                if (w -> indegree_ == 0)
                    a_queue.push (w);
            }
            if (a_queue.empty())
                std::cout << ".";
            else
                std::cout << ", ";
        }
        if (count != vertices_.size()-1)
            std::cout << "Cycle found "<< std::endl;
        else
            std::cout << std::endl;
    }
};

#endif /* CreateGraphAndTest_hpp */
