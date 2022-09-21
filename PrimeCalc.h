//
//  PrimeCalc.h
//  PrimeProject
//
//  Created by Kenny Kim on 9/20/22.
//

#ifndef PrimeCalc_h
#define PrimeCalc_h
class PrimeCalc{
private:
    /* Private variables */
    int gap;
    int determineNum = 2;
    int pairNum;
    int** pairList;
    int count = 0;
    int rangeNum;
    int pairListSize;
    
    /* Private functions */
    bool isPrime(int checkNum);
    bool setPair(int max);
    bool checkPrimePair(int index);
    bool checkBefores(int index);
public:
    PrimeCalc(); /* Constructor */
    
    /* Public functions */
    void setGap();
    void setPairNum();
    void setRange();
    void setPrivates();
    void setPairList();
    void calc();
    void checkTypePair();
    void display();
    void displayCount();
    
    ~PrimeCalc(); /* Destructor */
};

#endif /* PrimeCalc_h */
