#ifndef Heap_H
#define Heap_H
#include <iostream>
#include <queue>
#include <vector>
#include "Resort.h"

using namespace std;
//compare function for the built in priority queue
struct maxCurrent{
    bool operator()(Resort r1, Resort r2) const{
        return r1.getBaseDepth() > r2.getBaseDepth();
    }
};

class Heap{

public:
    
private:
    priority_queue<Resort, vector<Resort>, maxCurrent> maxBase;
};
#endif