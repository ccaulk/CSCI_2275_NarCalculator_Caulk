#ifndef Graph_H
#define Graph_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct resortVertex;

//struct representing the adjcent resorts
struct adjResorts{
    //node adjacent to and the distance
    resortVertex *v;
    int weight;
    adjResorts(resortVertex *res, int w){
        v = res;
        weight = w;
    }
};

//struct representing a resort
struct resortVertex{
    //name 
    string name;
    //variables used in searching
    resortVertex* parent;
    bool visited;
    int distance = INT32_MAX;
    //adjacency list
    vector<adjResorts*> adj;
    resortVertex(string n){
        name = n;
    }
};


class Graph{

    public:
        //constructor
        Graph(){};
        //adds a vertex
        void addVertex(string n);
        //adds an edge
        void addEdge(string str1, string str2, int w);
        //checks if two resorts are adjacent
        bool isAdjacent(string str1, string str2);
        //resets the search variables used in dijkstras and DFS and BFS
        void resetSearchVars();
        //prints the graph
        void printGraph();
        //dijkstras algorithm starting at n and finding shortest path to all other resorts
        void distacneFromX(string x);
        //returns the vertices vector to get the distances of the resorts
        vector<resortVertex*> getVertices();
        //gets the path from Y to X assumes that distance from X was called before hand
        vector<resortVertex*> getPathXToY(string y);
        //method to return the pointer to a resort in vertices
        resortVertex* findResortVertex(string n);
    private:
        //vector of vertices aka resorts
        vector <resortVertex*> vertices;
        //used in dijstras to determine a stop condition
        bool allVisitedCheck();
        //used in dijstras to get minResort
        resortVertex* getMinResort();
};



#endif