#include <iostream>
#include <vector>
#include "Heap.h"

using namespace std;

//public methods first

//pushes all the resorts onto the heap based on the max base depth
void Heap::addToMaxBase(vector<Resort> res){
    for(int i = 0; i < res.size(); i++){
        maxBase.push(res[i]);
    }
}
//pushes all the resorts onto the heap based on the most predicted snow
void Heap::addToMaxPred(vector<Resort> res){
    for(int i = 0; i < res.size(); i++){
        maxPred.push(res[i]);
    }
}
//pushes all the resorts onto the heap based on the min distance from location X
void Heap::addToMinFromX(vector<Resort> res){
    for(int i = 0; i < res.size(); i++){
        minFromX.push(res[i]);
    }
}
//pushes all the resorts onto the heap based on the most runs open
void Heap::addToMaxOp(vector<Resort> res){
    for(int i = 0; i < res.size(); i++){
        maxOp.push(res[i]);
    }
}
//pushes all the resorts onto the heap
void Heap::addToOverall(vector<Resort> res){
    for(int i = 0; i < res.size(); i++){
        overall.push(res[i]);
    }
}
//pushes all the resorts onto the heap based on the most runs open
void Heap::addTobestStartX(vector<Resort> res){
    for(int i = 0; i < res.size(); i++){
        bestStartX.push(res[i]);
    }
}

//adds the resort to the heap
void Heap::addOneMaxBase(Resort res){
    maxBase.push(res);
}
//adds the resort to the heap
void Heap::addOneMaxPred(Resort res){
    maxPred.push(res);
}
//adds the resort to the heap
void Heap::addOneMinFromX(Resort res){
    minFromX.push(res);
}
//adds the resort to the heap
void Heap::addOneMaxOp(Resort res){
    maxOp.push(res);
}
//adds the resort to the heap
void Heap::addOneOverall(Resort res){
    overall.push(res);
}
//adds the resort to the heap
void Heap::addOneBestStartX(Resort res){
    bestStartX.push(res);
}

//completely clears the heap
 void Heap::clearMaxBase(){
     while(!maxBase.empty()){
         maxBase.pop();
     }
 }
 //completely clears the heap
 void Heap::clearMaxPred(){
     while(!maxPred.empty()){
         maxPred.pop();
     }
 }
 //completely clears the heap
 void Heap::clearMinFromX(){
     while(!minFromX.empty()){
         minFromX.pop();
     }
 }
 //completely clears the heap
 void Heap::clearMaxOp(){
     while(!maxOp.empty()){
         maxOp.pop();
     }
 }
 //completely clears the heap
 void Heap::clearOverall(){
     while(!overall.empty()){
         overall.pop();
     }
 }
  //completely clears the heap
 void Heap::clearBestStartX(){
     while(!bestStartX.empty()){
        bestStartX.pop();
     }
 }

//returns the top of the heap and pops it
 Resort Heap::popMaxBase(){
     Resort temp = maxBase.top();
     maxBase.pop();
     return temp;
 }
 //returns the top of the heap and pops it
 Resort Heap::popMaxPred(){
     Resort temp = maxPred.top();
     maxPred.pop();
     return temp;
 }
 //returns the top of the heap and pops it
 Resort Heap::popMinFromX(){
     Resort temp = minFromX.top();
     minFromX.pop();
     return temp;
 }
 //returns the top of the heap and pops it
 Resort Heap::popMaxOp(){
     Resort temp = maxOp.top();
     maxOp.pop();
     return temp;
 }
  //returns the top of the heap and pops it
 Resort Heap::popOverall(){
     Resort temp = overall.top();
     overall.pop();
     return temp;
 }
 //returns the top of the heap and pops it
 Resort Heap::popBestStartX(){
     Resort temp = bestStartX.top();
     bestStartX.pop();
     return temp;
 }
