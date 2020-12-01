#include <iostream>

using namespace std;

class Resort{
    public:
        Resort(){};
        Resort(string n, string p, int nr, int nro, int ng, int nb, int nbl, int sa, int bd, int ca, int c, int ps);
        string getName();
        string getPass();
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
        void setNumRunsOpen();
        void setBaseDepth();
        void setpredictedSnow();
        void setDistanceFromX();
        double getPercentageOpen();
    private:
        string name;
        string pass;
        int numRuns;
        int numRunsOpen;
        int numGreen;
        int numBlue;
        int numBlack;
        int sizeAcreage;
        int baseDepth;
        int capacity;
        int crowed;
        int predictedSnow;
        int distanceFromX;
};
