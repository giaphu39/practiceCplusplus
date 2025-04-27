#pragma once

class Point{
    private:
        int iOx;
        int iOy;
    public:
        Point(int Ox = 0,int Oy= 0) : iOx(Ox) , iOy(Oy){}
        void inputPoint();
        void outputPoint();
    
        int getOx();
        int getOy();
    
        void setPoint(int ox, int oy);
        void setOx(int ox);
        void setOy ( int oy);
    
        void moveThroughVector(int ox , int oy); // vector không được dùng Point 
    };
    