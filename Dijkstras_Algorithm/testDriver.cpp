#include "Graph.hpp"
#include "GraphBase.hpp"

using namespace std;

int main()
{
    Graph g;
    string path;

//-----TEST CASES FROM 1ST CASE IN PP5TEST

    struct EdgeStruct { std::string a; std::string b; unsigned long w; };

    std::vector<std::string> vertices1 { "1", "2", "3", "4", "5", "6" };
    std::vector<EdgeStruct> edges1 {
    {"1", "2", 7}, {"1", "3", 9}, {"1", "6", 14}, {"2", "3", 10}, {"2", "4", 15}, {"3", "4", 11},
    {"3", "6", 2}, {"4", "5", 6}, {"5", "6", 9},
    };

    //adding each string in the vertices list
    for (const auto label : vertices1) g.addVertex(label);

    

    //adding each string in the edge list
    for (const auto &e : edges1) g.addEdge(e.a, e.b, e.w);

    g.printAdjList();

    g.removeVertex("3");
    
    g.printAdjList();

    g.shortestPath("1" , "5" , vertices1);



    return 0;
}