#include<iostream>

using namespace std;

class CTimeSpan{
    int iGio, iPhut, iGiay;
public:
    CTimeSpan(int IGio, int IPhut, int IGiay);

    friend ostream& operator <<(ostream& os, CTimeSpan This);
    friend istream& operator >>(istream& is, CTimeSpan& This);

    int During();

    friend CTimeSpan& operator+ (const CTimeSpan& a, const CTimeSpan& b);
    friend CTimeSpan& operator- (const CTimeSpan& a, const CTimeSpan& b);
    friend bool operator== (const CTimeSpan& a, const CTimeSpan& b);
    friend bool operator!= (const CTimeSpan& a, const CTimeSpan& b);
    friend bool operator> (const CTimeSpan& a, const CTimeSpan& b);
    friend bool operator>= (const CTimeSpan& a, const CTimeSpan& b);
    friend bool operator< (const CTimeSpan& a, const CTimeSpan& b);
    friend bool operator<= (const CTimeSpan& a, const CTimeSpan& b);

};



int main(){



    return 0;
}

CTimeSpan::CTimeSpan(int IGio = 0, int IPhut = 0, int IGiay = 0) : iGio(IGio), iPhut(IPhut) , iGiay(IGiay){}

ostream& operator <<(ostream& os, CTimeSpan This){
    os << This.iGiay << ":" << This.iPhut << ":" << This.iGio << endl;
}

