#include<iostream>
using namespace std;

#include "Point/Point.h"

class DaGiac{
private:
    Point ptDinhA, ptDinhB, ptDinhC;
public:
    DaGiac(Point DinhA = Point() ,Point DinhB = Point() , Point DinhC = Point() ) : ptDinhA(DinhA), ptDinhB(DinhB), ptDinhC(DinhC){}

    void InputDaGiac();
    void OutputDaGiac();
    



};

int main(){
    // Point a(7,5);
    // a.inputPoint();
    // a.moveThroughVector(7,1);
    // a.outputPoint();

    DaGiac b;
    b.OutputDaGiac();

    return 0;
}



void DaGiac::InputDaGiac(){
    ptDinhA.inputPoint();
    ptDinhB.inputPoint();
    ptDinhC.inputPoint();
}


void DaGiac::OutputDaGiac(){
    ptDinhA.outputPoint();
    ptDinhB.outputPoint();
    ptDinhC.outputPoint();
}