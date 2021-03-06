#ifndef Resort_H
#define Resort_H
#include <iostream>

using namespace std;

class Resort{
    public:
        Resort(){};
        Resort(string n, string p, int nl, int nr, int nro, int ng, int nb, int nbl, int sa, int bd, int ca, int c, int ps, int d);
        string getName();
        string getPass();
        int getNumLifts();
        int getNumRuns();
        int getNumRunsOpen();
        int getNumGreen();
        int getNumBlue();
        int getNumBlack();
        int getSize();
        int getBaseDepth();
        int getCapacity();
        int getCrowd();
        int getPredictedSnow();
        int getDistanceFromX();
        double getOverall();
        double getBestToX();
        void setOverall();
        void setBestToX();
        void setNumRunsOpen(int n);
        void setBaseDepth(int n);
        void setpredictedSnow(int n);
        void setDistanceFromX(int n);
        double percentageOpen();
        void printResort();
    private:
        string name;
        string pass;
        int numLifts;
        int numRuns;
        int numRunsOpen;
        int numGreen;
        int numBlue;
        int numBlack;
        int sizeAcreage;
        int baseDepth;
        int capacity;
        int crowd;
        int predictedSnow;
        int distanceFromX;
        double overall;
        double bestToX;
};
#endif