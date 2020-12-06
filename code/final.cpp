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
        temp.setOverall();
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
    //testing distance from
    // resortGraph->distacneFromX("Breckenridge");
    // vector<resortVertex*> temp = resortGraph->getVertices();
    // for(int i = 0; i < temp.size(); i++){
    //     cout << temp[i]->name << " distance from Breck is " << temp[i]->distance << endl;
    // }
    // //testing the Path XtoY
    // vector<resortVertex*> temp2 = resortGraph->getPathXToY("Howelsen Hill");
    // for(int i = 0; i < temp2.size(); i++){
    //     cout << temp2[i]->name << "<-";
    // }
    // cout<< endl;

    //adding the predicted snowTotals to the vector of resorts
    fstream infile3(argv[3]);
    int snowIn;
    int i = 0;
    //adds the new snow prediction to the vector of resorts
    while(getline(infile3,line)){
        stringstream ss(line);
        getline(ss,name,',');
        getline(ss,num);
        snowIn = stoi(num);
        if(name == resorts[i].getName())
            resorts[i].setpredictedSnow(snowIn);
        i++;
    }
    //for testing that the new predicted snow was added
    // for(int i = 0; i < resorts.size(); i++){
    //     resorts[i].printResort();
    // }

    //creating the heaps of the resorts
    //choosing a pointer so it is easier to pass to functions
    Heap *resortHeaps = new Heap();
    //adding heaps that don't require distance from X
    resortHeaps->addToMaxBase(resorts);
    resortHeaps->addToMaxPred(resorts);
    resortHeaps->addToMaxOp(resorts);
    resortHeaps->addToOverall(resorts);
    //menu
    std::string dmenu = "======Main Menu=====\n"
	    "1. Get resort with the most current snow\n"
		"2. Get resort with the most predicted snow\n"
        "3. Get resort with the most runs open\n"
        "4. Get resort closest to X\n"
        "5. Get next closest resorts to X\n"
		"6. Best resort overall\n"
		"7. Best resort from X\n"
        "8. Get next best resorts from X\n"
        "9. Reset Distance from X\n"
		"10. Quit";
    //prints menu and sets up the loop to run
    int choice;
    bool exit = false;
    cout << dmenu << endl;
    //options and running through
    while(cin >> choice) {
        // flush the newlines and other characters
        cin.clear();
        cin.ignore();
        switch (choice){
            case 1:{
                //get the resort
                Resort temp = resortHeaps->popMaxBase();
                //print
                cout << temp.getName() << " has a base depth of " << temp.getBaseDepth() << " inches" << endl;
                break;
            }
            case 2:{
                //get the resort
                Resort temp = resortHeaps->popMaxPred();
                //print
                cout << temp.getName() << " has a predicted storm total of " << temp.getPredictedSnow()<< " inches" << endl;
                break;
            }
            case 3:{
                //get the resort
                Resort temp = resortHeaps->popMaxOp();
                //print
                cout << temp.getName() << " has " << temp.percentageOpen()*100 << " percent of runs open" << endl;
                break;
            }
            case 4:{
                //gets the resort to base from or from denver or boulder
                cout << "Please enter a resort" << endl;
                cin >> str;
                //then will run dijkstras
                resortGraph->distacneFromX(str);
                //Then goes through all the resorts add updates the distance
                for(int i = 0; i < resorts.size(); i++){
                    string name = resorts[i].getName();
                    resorts[i].setDistanceFromX(resortGraph->findResortVertex(name)->distance);
                }
                //then adds the updated distances to the new heap
                resortHeaps->addToMinFromX(resorts);
                //gets the closest
                Resort temp = resortHeaps->popMinFromX();
                cout << temp.getName() << " is " << temp.getDistanceFromX() << " miles from " << str << endl;
                break;
            }
            case 5:{
                //gets the next closest resorts
                Resort temp = resortHeaps->popMinFromX();
                cout << temp.getName() << " is " << temp.getDistanceFromX() << " miles from " << str << endl;
                break;
            }
            case 6:{
                //get the resort
                Resort temp = resortHeaps->popOverall();
                //print
                cout << temp.getName() << " is one of the best overall ski resorts to visit with a score of " << temp.getOverall() << endl;
                break;
            }
            case 7:{
                //gets the resort to base from or from denver or boulder
                cout << "Please enter a resort" << endl;
                cin >> str;
                //then will run dijkstras
                resortGraph->distacneFromX(str);
                //Then goes through all the resorts add updates the distance
                for(int i = 0; i < resorts.size(); i++){
                    string name = resorts[i].getName();
                    resorts[i].setDistanceFromX(resortGraph->findResortVertex(name)->distance);
                }
                //make the heap
                resortHeaps->addTobestStartX(resorts);
                Resort temp = resortHeaps->popBestStartX();
                cout << temp.getName() << " is " << temp.getDistanceFromX() << " miles from " << str << " and is one of the best resorts nearby" <<endl;
                cout << "With a score of " << temp.getBestToX() << endl;
                break;
            }
            case 8:{
                //gets the next closest resorts that are good
                Resort temp = resortHeaps->popBestStartX();
                cout << temp.getName() << " is " << temp.getDistanceFromX() << " miles from " << str << " and is one of the best resorts nearby" <<endl;
                cout << "With a score of " << temp.getBestToX() << endl;
                break;
            }
            case 9:{
                //resets the distance from X so it can be used with a different resort
                resortGraph->resetSearchVars();
                //reset heap so it also works for the next time and no duplicate data
                resortHeaps->clearMinFromX();
                resortHeaps->clearBestStartX();
                break;
            }
            case 10:{
                exit = true;
                break;
            }
            default:
                break;
        }
        if(exit)
            break;
        cout << dmenu << endl;
    }
}