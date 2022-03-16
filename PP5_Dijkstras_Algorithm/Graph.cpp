#include "Graph.hpp"
#include "GraphBase.hpp"

using namespace std;

//predefining pairs for string int and int string
typedef pair<string,int> pairSI;
typedef pair<int,string> pairIS; 


Graph::Graph()
{
    //constructs object
}
//Creates and adds a vertex to the graph with label. No two vertices should have the same label.

//adds the vertex to the adjlist and the vertices to the vertexVec
void Graph::addVertex(std::string label)
{
    //fills adj list with just vertices
    
    vertexVec.push_back(label);
    adjList[label];
}
//Removes the vertex with label from the graph. Also removes the edges between that vertex and the other vertices of the graph.
void Graph::removeVertex(std::string label)
{

    //iterates through the adjacency list
    for (auto mapIter : adjList){
        //if any vertice value matches the passed in vertice value to delete it erase that member from the unordered map and breaks
        if(mapIter.first == label){
            cout<<"\nDeleting: "<<label<<" from list"<<endl;
            adjList.erase(label);
            break;
        }
    }
    //iterates through the adjacency list
    for (auto & mapIter : adjList)
    {
        //sets the list of pairs to the iterator itr 
        list< pair<string, int> > &adjacentVertices = mapIter.second;
        list< pair<string, int> >::iterator itr = adjacentVertices.begin();
        
        //iterates through the list of pairs 
        while(itr != adjacentVertices.end())
        {
            //if it finds the inputed edge it will delete it from the list of pairs
            if(itr->first == label)
            {
                itr = adjacentVertices.erase(itr);
            }
            else
            {
                ++itr;
            }
            
        }
    }
}

//Adds an edge of value weight to the graph between the vertex with label1 and the vertex with label2. A vertex with label1 and a vertex with label 2 must both exist,
//there must not already be an edge between those vertices, and a vertex cannot have an edge to itself.
//since this is suppose to reperesent a bidirectional use of djikstra's algorithm the edges are addes to the adjaceny list in both orders
//i.e 1 goes to 3 in weight 5 then also add that 3 goes to 1 in weight 5
void Graph::addEdge(std::string label1, std::string label2, unsigned long weight)
{
    adjList[label1].push_back(make_pair(label2, weight));
    adjList[label2].push_back(make_pair(label1, weight));
}
//Removes the edge from the graph between the vertex with label1 and the vertex with label2. A vertex with label1 and a vertex with label2 must both exist and there must be an edge between those vertices
//this was able to be handeled in removeVertex, however since it's a virtual function it has to be declared or the graph object won't be able to be constructed
void Graph::removeEdge(std::string label1, std::string label2)
{
  
}
//Calculates the shortest path betweren the vertex with startLabel and the vertex with endLabel using Dijkstra's Algorithm. A vector is passed into the method that stores the shortest path between the vertices.
//The return value is the sum of the edges between the start and end vertices on the shortest path.
unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path)
{
    

    //creating a priority queue
    priority_queue<pairIS, vector <pairIS> , greater<pairIS> > listPQ;

    //vertexVec; //contains all of the string names of the vertices
    //creating a unordered map and initializing all of the vertices to the max integer number
    unordered_map<string, int> distancesMap;

    for(unsigned int i = 0; i < vertexVec.size(); i++)
    {
        distancesMap.insert(make_pair(vertexVec.at(i), INT_MAX)); 
    }


  
    // Insert source itself in priority queue and initialize 
    // its distance as 0, which will be sorted to the top


    listPQ.push(make_pair(0, startLabel)); 

    //changing the value of the startLabel in the unordered map to 0
    
    distancesMap.at(startLabel) = 0;
  
    //loops until the priority queue is empty
    while (!listPQ.empty()) 
    { 
    
        //first value in the vertex pair is the minimum distance to the start
        //vertex string is the second value in the pair, 
        //this is so the priority queue sorts everything by distance
        string currVertex = listPQ.top().second; 
        listPQ.pop(); 

        //insert currVertex into adjlist and get the list of adjacent vectors

        list<pair<string, int>> tempList = adjList.at(currVertex);
        //iterator for temp list
        list<pair<string, int>>::iterator i; 


        //iterates through the list of <string, ints> at the current Vertex in the adjaceny list
        //so this is moving through all possible vertices the current vertex can go to
        for (i = tempList.begin(); i != tempList.end(); ++i) 
        { 
            // Get vertex label and weight of current adjacent edge
            string vertLabel = (*i).first; 
            int weight = (*i).second; 

            

            //  If there is shorter path to vertexLabel (string) through currVertex(string). 
            if (distancesMap.at(vertLabel) > distancesMap.at(currVertex) + weight) 
            {
                //adds all of the attempted paths travelled to path
                path.push_back(currVertex);
                path.push_back(vertLabel);
                
                //updates the distancesMap and priority queue with the new short distance
                distancesMap.at(vertLabel) = distancesMap.at(currVertex) + weight; 
                listPQ.push(make_pair(distancesMap.at(vertLabel), vertLabel)); 
            } 
        }
    } 
    
    
    //creating a temp vector
    vector<string> tempVec;
    //setting string toVert to the desired end label
    string toVert = endLabel;
    //adding the end label to the vector
    tempVec.push_back(endLabel);

    //iterating through path which currently looks like this
    //(5,6) (6,3) (4,3) (4,2) (6,1) (3,1) (2,1) (6,5) (4,3) (2,1)

    for(int i = path.size()-1; i >= 0; i--)
    {  
        //skipping the second instance
        if((i%2) == 0)
            continue;
        //if the start of the pair equals the last traveled node
        //set the next node to the location the node connects to
        if(path.at(i) == toVert){
            //getting the travel node
            toVert = path.at(i-1);
            //pushing the travel node into the vector
            tempVec.push_back(toVert);
        }
       
    }
    //setting path to the temp vector
    path = tempVec;
    //reversing path
    reverse(path.begin(), path.end());

    //return distance from start to end node
    return distancesMap.at(endLabel);
}
//prints the adjaceny list for testing
void Graph::printAdjList()
{
    cout << endl << "The Adjacency List-" << endl;
    for (auto& value : adjList) {
        string vertex = value.first;
        list< pair<string, int> > adjacentVertices = value.second;
        list< pair<string, int> >::iterator itr = adjacentVertices.begin();
         
        cout << "adjacencyList[" << vertex << "]";
          
        while (itr != adjacentVertices.end()) {
            cout << " -> " << (*itr).first << " (" << (*itr).second << ")";
            ++itr;
        }
         
        cout << endl;
    }
}

