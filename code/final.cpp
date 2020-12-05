//final Prjoect Nar Calculator
//Caleb Caulk
//11/19/2020
//Instructor Rhonda Hoenigman
//This is the main file that will run all of the aspects of the final program
//What the program will do is described in the READMe.md

//included libraries
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Heap.h"
#include "Graph.h"
#include "Resort.h"

using namespace std;
//functions to call that will determine the best place to ski based on what the function is

//will return the best place to ski based on curent base depth
// Resort* bestCurrentNar(){

// }
// //will return the best place to ski based on current base depth and within a certain distance of X
// Resort* bestCurrentNarFromX(){

// }
// //will return the best place to ski based on predicted snow 
// Resort* bestPredictedNar(){

// }
// //will return the best place to ski based on predicted snow and within a certain distance of X
// Resort* bestPredictedNarFromX(){
    
// }


//main to run everything
int main(int argc, const char * argv[]) {
    //add all the resorts to a vector to then add to heaps and graph
    vector<Resort> resorts;
    //the first argument is the file with all the ski resorts
    fstream infile(argv[1]);
    string line, name, pass,data;
    int nl,nr,nro,ng,nb,nbl,sa,bd,ca,c,ps,d;
    //getting all the data from the file making a resort object and adding it to the resorts vector
    while(getline(infile,line)){
        //getting the data
        stringstream ss(line);
        getline(ss,name,',');
        getline(ss,pass,',');
        getline(ss,data,',');
        nl = stoi(data);
        getline(ss,data,',');
        nr = stoi(data);
        getline(ss,data,',');
        nro = stoi(data);
        getline(ss,data,',');
        ng = stoi(data);
        getline(ss,data,',');
        nb = stoi(data);
        getline(ss,data,',');
        nbl = stoi(data);
        getline(ss,data,',');
        sa = stoi(data);
        getline(ss,data,',');
        bd = stoi(data);
        getline(ss,data,',');
        ca = stoi(data);
        getline(ss,data,',');
        c = stoi(data);
        getline(ss,data,',');
        ps = stoi(data);
        getline(ss,data);
        d =stoi(data);
        //making a resort object and adding it to the resorts vector
        Resort temp(name,pass,nl,nr,nro,ng,nb,nbl,sa,bd,ca,c,ps,d);
        resorts.push_back(temp);
    }
    //making sure the resorts were stored correctly this is for testing
    // for(int i = 0; i < resorts.size(); i++){
    //     resorts[i].printResort();
    // }

    //making a Graph of all of the resorts in Colorado based on highways and distance in miles using the second
    //command line argument
    fstream infile2(argv[2]);
    //varaibles to store data and make vertices
    string part,str,num;
    int miles,count;
    //Graph object chose pointer becasue it will be passed by reference in other methods to
    //calculate stuff
    Graph* resortGraph = new Graph();
    //loop thorugh all lines of the csv file
    while(getline(infile2,line)){
        //get the first name which will be the vertex
        stringstream ss(line);
        getline(ss,name,',');
        resortGraph->addVertex(name);
        count = 0;
        //Then get the adjacent vertices and distance and add to adjResorts
        while(getline(ss,part,',')){
            //if it is even it is a name
            if(count % 2 == 0){
                str = part;
            //odd is a distance and add to the graph
            }else{
                num = part;
                miles = stoi(num);
                resortGraph->addEdge(name,str,miles);
            }
            //indexing to get name and distance right
            count ++;
        }
    }
    //print graph for testing
    // resortGraph->printGraph();
    resortGraph->distacneFromX("Breckenridge");
    vector<resortVertex*> temp = resortGraph->getVertices();
    for(int i = 0; i < temp.size(); i++){
        cout << temp[i]->name << " distance from Breck is " << temp[i]->distance << endl;
    }
}