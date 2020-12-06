#ifndef Heap_H
#define Heap_H
#include <iostream>
#include <queue>
#include <vector>
#include "Resort.h"

using namespace std;

//compare function for the built in priority queue for determing the max base depth
struct maxCurrent{
    bool operator()(Resort r1, Resort r2) const{
        return r1.getBaseDepth() < r2.getBaseDepth();
    }
};
//compare function for the heap to determine the most predicted snow
struct maxPredicted{
    bool operator()(Resort r1, Resort r2) const{
        return r1.getPredictedSnow() < r2.getPredictedSnow();
    }
};
//compare function for the heap that is closest to x
struct minDisFromX{
    bool operator()(Resort r1, Resort r2) const{
        return r1.getDistanceFromX() > r2.getDistanceFromX();
    }
};
//compare function for the heap for the resort with the most open
struct maxOpen{
    bool operator()(Resort r1, Resort r2) const{
        return r1.percentageOpen() < r2.percentageOpen();
    }
};
struct bestOverall{
    bool operator()(Resort r1, Resort r2) const{
        return r1.getOverall() < r2.getOverall();
    }
};
struct bestFromX{
    bool operator()(Resort r1, Resort r2) const{
        return r1.getBestToX() < r2.getBestToX();
    }
};

class Heap{

    public:
        Heap(){};
        //add the entire vector in the designated heap
        void addToMaxBase(vector<Resort> res);
        void addToMaxPred(vector<Resort> res);
        void addToMinFromX(vector<Resort> res);
        void addToMaxOp(vector<Resort> res);
        void addToOverall(vector<Resort> res);
        void addTobestStartX(vector<Resort> res);
        //adds just one resort on the heap
        void addOneMaxBase(Resort res);
        void addOneMaxPred(Resort res);
        void addOneMinFromX(Resort res);
        void addOneMaxOp(Resort res);
        void addOneOverall(Resort res);
        void addOneBestStartX(Resort res);
        //clear the designated heap
        void clearMaxBase();
        void clearMaxPred();
        void clearMinFromX();
        void clearMaxOp();
        void clearOverall();
        void clearBestStartX();
        //pop the top from the heap
        Resort popMaxBase();
        Resort popMaxPred();
        Resort popMinFromX();
        Resort popMaxOp();
        Resort popOverall();
        Resort popBestStartX();
    private:
        //all the heaps used to store various data about resorts
        priority_queue<Resort, vector<Resort>, maxCurrent> maxBase;
        priority_queue<Resort, vector<Resort>, maxPredicted> maxPred;
        priority_queue<Resort, vector<Resort>, minDisFromX> minFromX;
        priority_queue<Resort, vector<Resort>, maxOpen> maxOp;
        priority_queue<Resort, vector<Resort>, bestOverall> overall;
        priority_queue<Resort, vector<Resort>, bestFromX> bestStartX;
};
#endif