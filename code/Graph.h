#ifndef Graph_H
#define Graph_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct resortVertex;

struct adjResorts{
    resortVertex *v;
    int weight;
    adjResorts(resortVertex *res, int w){
        v = res;
        weight = w;
    }
};

struct resortVertex{
    string name;
    resortVertex* parent;
    bool visited;
    int distance;
    vector<adjResorts*> adj;
    resortVertex(string n){
        name = n;
    }
};


class Graph{
    
    public:
        Graph(){};
        void addVertex(string n);
        void addEdge(string str1, string str2, int w);
        bool isAdjacent(string str1, string str2);
        void resetSearchVars();
        void printGraph();
    private:
        vector <resortVertex*> vertices;
        resortVertex* findResortVertex(string n);
};



#endif