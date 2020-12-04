#include <iostream>
#include "Graph.h"
#include <vector>

using namespace std;

//public methods

//will add the resort into the graph
void Graph::addVertex(string n){
    //if the vertex doesn't exist then add it
    if(!findResortVertex(n)){
        vertices.push_back(new resortVertex(n));
    }
}

//will add an edge between 2 vertices and create a vertex if it doesn't exist
//and add an edge between them and if the is an edge between them don't ass another
void Graph::addEdge(string str1, string str2, int w){
    resortVertex *res1 = findResortVertex(str1);
    resortVertex *res2 = findResortVertex(str2);
    //if the first vertex isn't in the graph add it to the 
    if(!res1)
        addVertex(str1);
    if(!res2)
        addVertex(str2);
    //check to see if there is an edge between the two resorts already
    for(int i = 0; i < res1->adj.size(); i++){
        if(res1->adj[i]->v->name == res2->name)
            return;
    }
    //otherwise create a vertex between the two resorts and add to both adjacency lists
    adjResorts* one =  new adjResorts(res2, w);
    adjResorts* two = new adjResorts(res1,w);
    res1->adj.push_back(one);
    res2->adj.push_back(two);

}

//will print out the vertices with the adjacency lists
void Graph::printGraph(){
    //gets the resort
    for(int i = 0; i < vertices.size(); i++){
        //prints the resort then all of its adjacent resorts
        cout << vertices[i]->name <<" : ";
        for(int j = 0; j < vertices[i]->adj.size(); j++){
            cout << vertices[i]->adj[j]->v->name << ", ";
        }
        cout << endl;
    }
}
//priavte methods

//will return the vertex and null if it isn't there
resortVertex* Graph::findResortVertex(string n){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == n)
            return vertices[i];
    }
    return NULL;
}
