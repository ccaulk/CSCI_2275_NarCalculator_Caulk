#include <iostream>
#include "Resort.h"

using namespace std;

//public mehtods
//constructor
Resort::Resort(string n, string p, int nl, int nr, int nro, int ng, int nb, int nbl, int sa, int bd, int ca, int c, int ps, int d){
    name = n;
    pass = p;
    numLifts = nl;
    numRuns = nr;
    numRunsOpen = nro;
    numGreen = ng;
    numBlue = nb;
    numBlack = nbl;
    sizeAcreage = sa;
    baseDepth = bd;
    capacity = ca;
    crowd = c;
    predictedSnow = ps;
    distanceFromX = d;
}
//getters for every variable
string Resort::getName(){
    return name;
}
string Resort::getPass(){
    return pass;
}
int Resort::getNumLifts(){
    return numLifts;
}
int Resort::getNumRuns(){
    return numRuns;
}
int Resort::getNumRunsOpen(){
    return numRunsOpen;
}
int Resort::getNumGreen(){
    return numGreen;
}
int Resort::getNumBlue(){
    return numBlue;
}
int Resort::getNumBlack(){
    return numBlack;
}
int Resort::getSize(){
    return sizeAcreage;
}
int Resort::getBaseDepth(){
    return baseDepth;
}
int Resort::getCapacity(){
    return capacity;
}
int Resort::getCrowd(){
    return crowd;
}
int Resort::getPredictedSnow(){
    return predictedSnow;
}
int Resort::getDistanceFromX(){
    return distanceFromX;
}
double Resort::getOverall(){
    return overall;
}
double Resort::getBestToX(){
    return bestToX;
}
//sets for variables that can change
//this sets a rating to the resort based on snow depth amount open crowd and predicted
void Resort::setOverall(){
    if(crowd == 0)
    //assign crowd value to 5 which is semi busy
        crowd = 5;
    if(predictedSnow == 0)
    //set to 1 to not make calculation 0
        predictedSnow = 1;
        //calculation
    overall = ((double)baseDepth * (double)predictedSnow * (double)percentageOpen()*100) / (double)crowd;
}
//this sets a rating to the resort based on overall and distance from X
void Resort::setBestToX(){
    if(crowd == 0)
    //assign crowd value to 5 which is semi busy
        crowd = 5;
    if(predictedSnow == 0)
    //set to 1 to not affect calculation
        predictedSnow = 1;
        //calculation
    bestToX = ((double)baseDepth * (double)predictedSnow * (double)percentageOpen() *100) / ((double)crowd*(double)distanceFromX);
}
void Resort::setNumRunsOpen(int n){
    numRunsOpen = n;
}
void Resort::setBaseDepth(int n){
    baseDepth = n;
}
void Resort::setpredictedSnow(int n){
    predictedSnow = n;
}
void Resort::setDistanceFromX(int n){
    distanceFromX = n;
}
//methods to calculate other aspects of the resort
double Resort::percentageOpen(){
    return (double)(numRunsOpen)/(double)(numRuns);
}
//prints out a resort and all the data with it
void Resort::printResort(){
    cout << name<<","<<pass<<","<<numLifts<<","<<numRuns<<","<<numRunsOpen<<","<<numGreen<<","
    <<numBlue<<","<<numBlack<<","<<sizeAcreage<<","<<baseDepth<<","<<capacity<<","<<crowd<<","
    <<predictedSnow<<","<<distanceFromX<<endl;
}
