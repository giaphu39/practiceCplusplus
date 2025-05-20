#include<iostream>

using namespace std;

class CTimeSpan{
    int iGio, iPhut, iGiay;
public:
    // CTimeSpan(int IGio, int IPhut, int IGiay);

    CTimeSpan(int IGiay = 0, int IPhut = 0, int IGio = 0) : iGio(IGio), iPhut(IPhut), iGiay(IGiay) {}


    friend ostream& operator <<(ostream& os, CTimeSpan This);
    friend istream& operator >>(istream& is, CTimeSpan& This);

    int During() const; // cần làm vậy để khớp với const ở dưới

    // chỉ cộng thời lượng với thời lượng được thôi
    CTimeSpan operator+ ( const CTimeSpan& other);
    CTimeSpan operator- ( const CTimeSpan& other); // do tham chiếu nên sai
    bool operator== ( const CTimeSpan& other);
    bool operator!= ( const CTimeSpan& other);
    bool operator> ( const CTimeSpan& other);
    bool operator>= ( const CTimeSpan& other);
    bool operator< ( const CTimeSpan& other);
    bool operator<= ( const CTimeSpan& other);

    CTimeSpan setTime();

};





int main(){

    CTimeSpan a(3,4,1);
    CTimeSpan b;
    cin >> b;
    // cout << b;
    CTimeSpan c = a + b;

    cout << c;

    return 0;
}

// CTimeSpan::CTimeSpan(int IGio = 0, int IPhut = 0, int IGiay = 0) : iGio(IGio), iPhut(IPhut) , iGiay(IGiay){}

ostream& operator <<(ostream& os, CTimeSpan This){
    os << This.iGiay << ":" << This.iPhut << ":" << This.iGio << endl;
    return os;
}

istream& operator >> (istream& is, CTimeSpan& This){
    is >> This.iGiay >> This.iPhut >> This.iGio ;
    return is;
}

int CTimeSpan:: During () const{
    return iGio*3600 + iPhut * 60 + iGiay;
}

CTimeSpan CTimeSpan::operator+ ( const CTimeSpan& other){
    CTimeSpan res;
    
    res.iGio = iGio + other.iGio;
    res.iPhut = iPhut + other.iPhut;
    res.iGiay = iGiay + other.iGiay;

    res.setTime();
    return res;
}

CTimeSpan CTimeSpan::operator- ( const CTimeSpan& other){
    CTimeSpan res;
    
    res.iGio = iGio - other.iGio;
    res.iPhut = iPhut - other.iPhut;
    res.iGiay = iGiay - other.iGiay;

    res.setTime();
    return res;
}

bool CTimeSpan::operator== ( const CTimeSpan& other){
    return this->During() == other.During();
}

bool CTimeSpan::operator!= ( const CTimeSpan& other){
    return this->During() != other.During();
}

bool CTimeSpan::operator>= ( const CTimeSpan& other){
    return this->During() >= other.During();
}
bool CTimeSpan::operator> ( const CTimeSpan& other){
    return this->During() > other.During();
}
bool CTimeSpan::operator<= ( const CTimeSpan& other){
    return this->During() <= other.During();
}
bool CTimeSpan::operator< ( const CTimeSpan& other){
    return this->During() < other.During();
}
// có thể để lớp bạn, 

CTimeSpan CTimeSpan::setTime(){ // tìm hiểu kĩ tại sao dùng & cái kiểu trả về 
    int temp = During();
    this->iGio = temp / 3600;
    temp%=3600;
    this->iPhut = temp / 60;
    temp%=60;
    this->iGiay = temp;

    return *this; 
}


