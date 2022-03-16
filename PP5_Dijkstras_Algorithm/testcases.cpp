#include <unordered_map>
#include <list>
#include <iostream>
#include <vector>

using namespace std;


unordered_map<string, list<pair<string, int>>> adjList; 

struct EdgeStruct { std::string a; std::string b; unsigned long w; };

void print(list<pair<string,int>> const &list)
{
    for (auto const& i: list) {
        std::cout << i.first << " " << i.second << "\n";
    }
}
void addEdge(std::string label1, std::string label2, unsigned long weight)
{
    adjList[label1].push_back(make_pair(label2, weight));
}
void printAdjList()
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

int main()
{

    list<pair<string,int>> testListPairs;
    
    //vector<pair<string, int>> testVec {
    //{"2", 7}, {"3", 9}, {"6", 14}, {"3", 10}, {"4", 15}, {"4", 11},
    //{"6", 2}, {"5", 6}, {"6", 9},
    //};
    

    std::vector<EdgeStruct> testVec {
    {"1", "2", 7}, {"1", "3", 9}, {"1", "6", 14}, {"2", "3", 10}, {"2", "4", 15}, {"3", "4", 11},
    {"3", "6", 2}, {"4", "5", 6}, {"5", "6", 9},
    };




    for (const auto &e : testVec) addEdge(e.a, e.b, e.w);

    /*for (int i = 0; i < testVec.size(); i++)
    {
        testListPairs.push_back(testVec.at(i));

    }*/
    cout<<"before deleteing 3"<<endl;
    printAdjList();

    /*list<pair<string, int>>::iterator i = testListPairs.begin();
    while(i != testListPairs.end())
    {
        if (i->first == "3")
        {
            i = testListPairs.erase(i);
        }
        else
        ++i;
        
    }*/
    //iterates through the adjacency list
    for (auto mapIter : adjList){
        //if any vertice value matches the passed in vertice value to delete it erase that member from the unordered map and breaks
        if(mapIter.first == "3"){
            cout<<"\nDeleting: "<<"3"<<" from list"<<endl;
            adjList.erase("3");
            break;
        }
    }
    for (auto mapIter : adjList){
        //setting second value of unordered_map to adjacentVertices, which is a list of pairs just like in the map
        list< pair<string, int> > adjacentVertices = mapIter.second;
        //list< pair<string, int> >::iterator itr = adjacentVertices.begin();
        for(auto itr = adjacentVertices.begin(); itr != adjacentVertices.end(); itr++)
        {
            cout<<itr->first<<" "<<itr->second<<endl;
            (adjacentVertices.erase(itr));
            //if(itr->first == "3")
            //  adjacentVertices.erase("3");
        }
        //cout<<"adjList second: " <<  <<endl;
        
    }
    cout<<"after deleting 3"<<endl;
    printAdjList();
}

