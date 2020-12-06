#include <iostream>
#include "Graph.h"
#include <vector>

using namespace std;

//public methods

//will add the resort into the graph
void Graph::addVertex(string n){
    //if the vertex doesn't exist then add it
    if(findResortVertex(n) == NULL){
        resortVertex *temp = new resortVertex(n);
        vertices.push_back(temp);
    }
}
//will add an edge between 2 vertices and create a vertex if it doesn't exist
//and add an edge between them and if the is an edge between them don't add another
void Graph::addEdge(string str1, string str2, int w){
    resortVertex *res1 = findResortVertex(str1);
    resortVertex *res2 = findResortVertex(str2);
    //if the first vertex isn't in the graph add it to the 
    if(res1 == NULL){
        addVertex(str1);
        //need to then make res1 points to an actual vertex instead of null
        res1 = findResortVertex(str1);
    }
    //same for res2
    if(res2 == NULL){
        addVertex(str2);
        res2 = findResortVertex(str2);
    }
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
            cout << vertices[i]->adj[j]->v->name << ","<< vertices[i]->adj[j]->weight<< "*";
        }
        cout << endl;
    }
}
//resets the variables needed to run BFS DFS and dijkstra's
void Graph::resetSearchVars(){
    //goes through each vertex and resets visited distance and parent
    for(int i = 0; i < vertices.size(); i++){
        vertices[i]->visited = false;
        vertices[i]->distance = INT32_MAX;
        vertices[i]->parent = NULL;
    }
}
//will return true if two resorts are adjacent
bool Graph::isAdjacent(string str1, string str2){
    //loop thorugh one of the resorts adjacency lists and if there are adjacent retrun true
    resortVertex* res = findResortVertex(str1);
    for(int i = 0; i < res->adj.size(); i++){
        if(res->adj[i]->v->name == str2){
            return true;
        }
    }
    //otherwise return false
    return false;
}
//Will find every resorts shortest path from starting point X using dijkstras algorithm
void Graph::distacneFromX(string str){
    //get the starting place vertex
    resortVertex* source = findResortVertex(str);
    if(source == NULL){
        cout << "The starting point doesn't exist" <<endl;
        return;
    }
    //making the source the min node
    source->distance = 0;
    //set parent to null beacuse it is the starting point
    source->parent = NULL;
    //while some nodes still need to be visited 
    while(!allVisitedCheck()){
        //get the min resort distance wise the first one will be the source
        resortVertex* minNode = getMinResort();
        //can no longer be the min resort
        minNode->visited = true;
        for(int i = 0; i < minNode->adj.size(); i++){
            //sets the adjacent nodes distances to the minimum from the source by re-routing in needed
            if(minNode->adj[i]->v->distance > minNode->distance + minNode->adj[i]->weight){
                minNode->adj[i]->v->distance = minNode->distance + minNode->adj[i]->weight;
                minNode->adj[i]->v->parent = minNode;
            }
        }
    }
}
//will return the vertices vector
vector<resortVertex*> Graph::getVertices(){
    return vertices;
}
//will return the path from x to y in a vector assumes that distanceFromX was called
vector<resortVertex*> Graph::getPathXToY(string y){
    //find the end vertex
    resortVertex* end = findResortVertex(y);
    //vector to return
    vector<resortVertex*> result;
    while(end != NULL){
        //pushes the resort onto the vector and then moves up the parent chain until NULL
        result.push_back(end);
        end = end->parent;
    }
    return result;
}
//will return the vertex and null if it isn't there
resortVertex* Graph::findResortVertex(string n){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == n)
            return vertices[i];
    }
    return NULL;
}

//priavte methods

//will return if all the resorts have been visited
bool Graph::allVisitedCheck(){
    //goes through each vertex and checks if it was visited
    for(int i = 0; i < vertices.size(); i++){
        //if one vertex isn't visited returns false
        if(!vertices[i]->visited){
            return false;
        }
    }
    //otherwise true
    return true;
}
//will return the node with the least distance that hasn't been visited
resortVertex* Graph::getMinResort(){
    //min and resort to return
    int min = INT32_MAX;
    resortVertex* result;
    //go through all the vertices
    for(int i = 0; i < vertices.size();i++){
        //if it hasn't been visited then heck if it is a min node
        if(!vertices[i]->visited){
            if(vertices[i]->distance < min){
                //if it is min update values
                min = vertices[i]->distance;
                result = vertices[i];
            }
        }
    }
    //return min node
    return result;
}

