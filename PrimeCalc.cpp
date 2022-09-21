//
//  PrimeCalc.cpp
//  PrimeProject
//
//  Created by Kenny Kim on 9/20/22.
//
#include "PrimeCalc.h"
#include <stdio.h>
#include <iostream>

using namespace std;

/* Constructor */
PrimeCalc::PrimeCalc(){
    gap = -1;
    pairNum = -1;
    rangeNum = -1;
}

/*
 Function Name: setGap
 Parameter: None
 Return Type: None
 set Gap value
 */
void PrimeCalc::setGap(){
    cout << "Enter a gap: ";
    cin >> this->gap;
    cout << endl;
}

/*
 Function Name: setPairNum
 Parameter: None
 Return Value: None
 set the # of prime numbers in the pair
 */
void PrimeCalc::setPairNum(){
    cout << "Enter # of numbers in the pair: ";
    cin >> this->pairNum;
    cout << endl;
}

/*
 Function Name: setRange
 Parameter: None
 Return Value: None
 set the range to calculate the prime pairs
 */
void PrimeCalc::setRange(){
    cout << "Enter the range to calculate: ";
    cin >> this->rangeNum;
    cout << endl;
}

/*
 Function Name: setPairList
 Parameter: None
 Return Value: None
 set the pair list
 */
void PrimeCalc::setPairList(){
    pairListSize = (rangeNum / pairNum);
    pairList = new int*[pairListSize];
    for (int i = 0; i < rangeNum; ++i)
        pairList[i] = new int[pairNum];
}

/* setPrivates(): set private variables */
void PrimeCalc::setPrivates(){
    setGap();
    setPairNum();
    setRange();
    setPairList();
    
}

// I don't use math library for this project.
/*
 Function Name: isPrime
 Parameter: int checkNum
 Return Value: boolean
 Check if the checkNum is prime or not
*/
bool PrimeCalc::isPrime(int checkNum){
    for (int i = 2; i < checkNum; ++i){
        if (checkNum % i == 0)
            return false;
    }
    return true;
}

/*
 Function Name: checkPair
 Parameter: int max
 Return Value: boolean
 set the prime pair into the pair list
 */
bool PrimeCalc::setPair(int max){
    for (int k = 0; k < pairNum; ++k){
        pairList[count][k] = max - (pairNum - 1 - k) * gap;
    }
    ++count;
    return true;
}

/*
 Function Name: checkPrimePair
 Parameter: int index
 Return Value: boolean
 check if the numer has number(s)(depends on pair #) with a specific gap & it's prime
 */
bool PrimeCalc::checkPrimePair(int index){
    return (index - ((pairNum - 1) * gap) > 1 && isPrime(index));
}

/*
 Function Name: checkBefores
 Parameter: int index
 Return Value: boolean
 check if the previous numbers are prime
 */
bool PrimeCalc::checkBefores(int index){
    int* tempPair = new int[pairNum];
    int checkBefore = index - gap;
    for (int i = 0; i < pairNum - 1; ++i){
        if (!isPrime(checkBefore)){
            delete[] tempPair;
            tempPair = nullptr;
            return false;
        }
        tempPair[i] = checkBefore;
        checkBefore -= gap;
    }
    delete[] tempPair;
    tempPair = nullptr;
    return true;
}

/*
 Function Name: calc
 Parameter: None
 Return Value: None
 calculate the prime pair list
 */
void PrimeCalc::calc(){
    for (int i = determineNum; i < rangeNum; ++i){
        if (checkPrimePair(i)){
            if (checkBefores(i))
                setPair(i);
        }
    }
}

/*
 Function Name: display
 Parameter: None
 Return Value: None
 display prime pairs in the specific range that the user set.
 */
void PrimeCalc::display(){
    this->checkTypePair();
    for (int i = 0; i < count; ++i){
        cout << "(";
        for (int j = 0; j < pairNum; ++j){
            cout << pairList[i][j];
            if (j != pairNum - 1)
                cout << ", ";
        }
        cout << ")";
        if (i != count - 1)
            cout << ", ";
    }
    cout << endl;
    displayCount();
}

/*
 Function Name: displayCount
 Parameter: None
 Return Value: None
 display number of the prime pair
 */
void PrimeCalc::displayCount(){
    cout << "COUNT: " << count << endl;
}

/*
 Function Name: checkTypePair
 Parameter: None
 Return Value: None
 check and display the type of the prime pair
 */
void PrimeCalc::checkTypePair(){
    if (this->gap == 2) // twin
        cout << "Twin Prime: " << endl;
    else if (this->gap == 4) // cousin
        cout << "Cousin Prime: " << endl;
    else if (this->gap == 6) // sexy
        cout << "Sexy Prime: " << endl;
    else // others
        cout << "Prime Numbers with " << this->gap << " gap: " << endl;
}

/* Destructor */
PrimeCalc::~PrimeCalc(){
    for (int i = 0; i < pairListSize; ++i){
        delete pairList[i];
        pairList[i] = nullptr;
    }
    delete[] pairList;
    pairList = nullptr;
    
}
