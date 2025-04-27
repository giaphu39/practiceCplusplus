#include "Point.h"
#include <iostream>

void Point::inputPoint(){
    cin >> iOx >> iOy;
}

void Point::outputPoint(){
    cout << "(" << iOx << "," << iOy << ")" << endl;
}

int Point::getOx(){
    return iOx;
}

int Point::getOy(){
    return iOy;
}

void Point::setPoint(int ox , int oy){
    iOx = ox;
    iOy = oy;
}

void Point::setOx(int ox){
    iOx = ox;
}

void Point::setOy( int oy){
    iOy = oy;
}

void Point::moveThroughVector(int ox, int oy){
    iOx += ox;
    iOy += oy;
}
