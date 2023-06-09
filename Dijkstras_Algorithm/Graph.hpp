#ifndef GRAPH_H
#define GRAPH_H

#include "GraphBase.hpp"
#include <unordered_map>
#include <list>
#include <iostream>
#include <queue>
#include <math.h>
#include <climits> 
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Graph: public GraphBase 
{
    private:
        //for edge {"1", "2", 7}
        //1 represents the vertice, 2 means that 1 is going to 2, and 7 is the weight of the edge
        //so this map stores <1, list<pair<2, 7>>>
        //when you call for vertice 1 it will print the list of pairs containing all the vertices 1 goes to and those edges
        unordered_map<string, list<pair<string, int>>> adjList; 
        priority_queue<pair<string, int>> pathPQ; 
        vector<string> vertexVec;
    public:
        Graph();
        //Creates and adds a vertex to the graph with label. No two vertices should have the same label.
        void addVertex(std::string label);
        //Removes the vertex with label from the graph. Also removes the edges between that vertex and the other vertices of the graph.
        void removeVertex(std::string label);
        //Adds an edge of value weight to the graph between the vertex with label1 and the vertex with label2. A vertex with label1 and a vertex with label 2 must both exist,
        //there must not already be an edge between those vertices, and a vertex cannot have an edge to itself.
        void addEdge(std::string label1, std::string label2, unsigned long weight);
        //Removes the edge from the graph between the vertex with label1 and the vertex with label2. A vertex with label1 and a vertex with label2 must both exist and there must be an edge between those vertices
        void removeEdge(std::string label1, std::string label2);
        //Calculates the shortest path betweren the vertex with startLabel and the vertex with endLabel using Dijkstra's Algorithm. A vector is passed into the method that stores the shortest path between the vertices.
        //The return value is the sum of the edges between the start and end vertices on the shortest path.
        unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);
        void printAdjList();
        void printQueue(priority_queue<pair<string, int>> pq);
     

};

#endif