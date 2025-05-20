#include<iostream>

using namespace std;

class CTimeSpan{
    int iGio, iPhut, iGiay;
public:
    CTimeSpan(int IGiay = 0, int IPhut = 0, int IGio = 0) : iGio(IGio), iPhut(IPhut), iGiay(IGiay) {}


    friend ostream& operator <<(ostream& os, CTimeSpan This);
    friend istream& operator >>(istream& is, CTimeSpan& This);

    int During() const; 

    CTimeSpan operator+ ( const CTimeSpan& other);
    CTimeSpan operator- ( const CTimeSpan& other);
    bool operator== ( const CTimeSpan& other);
    bool operator!= ( const CTimeSpan& other);
    bool operator> ( const CTimeSpan& other);
    bool operator>= ( const CTimeSpan& other);
    bool operator< ( const CTimeSpan& other);
    bool operator<= ( const CTimeSpan& other);

    CTimeSpan setTime();

    int getIGio() const;
    int getIPhut() const;
    int getIGiay() const;

    void setIGio(int gio);
    void setIPhut(int phut);
    void setIGiay(int giay);

};

class CTime{
    int iGio, iPhut, iGiay;
public:
    CTime(int IGiay = 0, int IPhut = 0, int IGio = 0) : iGio(IGio), iPhut(IPhut), iGiay(IGiay) {}

    friend ostream& operator <<(ostream& os, CTime This);
    friend istream& operator >>(istream& is, CTime& This);


    CTime operator+(int giay);
    CTime operator-(int giay);
    CTime operator+ ( const CTimeSpan& other );
    CTimeSpan operator- (  const CTime& other ); 

    CTime operator++();
    CTime operator++(int);
    CTime operator--();
    CTime operator--(int);

    CTime setTime();

};

int main(){

    CTime a(0,0,0);
    cout << --a;
    CTimeSpan b;
    cin >> b;
    cout << a + b;

    CTimeSpan c(7,7,7);
    cout << (c == b);
    cout << (c < b) <<endl;

    cout << a + 86400;
    cout << a + 86401;
    cout << a - 3599;

    return 0;
}

ostream& operator <<(ostream& os, CTimeSpan This){
    if(This.iGio < 0 || This.iPhut <0 || This.iGiay < 0){
        cout <<"error"<<endl;
        return os;
    }
    os << This.iGio << ":" << This.iPhut << ":" << This.iGiay << endl;
    return os;
}

istream& operator >> (istream& is, CTimeSpan& This){
    is >> This.iGiay >> This.iPhut >> This.iGio ;
    while(This.iGiay < 0){
        cout << "vui long nhap lai giay:";
        is >> This.iGiay;
    }
    while(This.iPhut < 0){
        cout << "vui long nhap lai phut:";
        is >> This.iPhut;
    }
    while(This.iGio < 0){ // 24 h tối là 12 h sáng
        cout << "vui long nhap lai gio:";
        is >> This.iGio;
    }
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

CTimeSpan CTimeSpan::setTime(){ 
    int temp = During();
    this->iGio = temp / 3600;
    temp%=3600;
    this->iPhut = temp / 60;
    temp%=60;
    this->iGiay = temp;

    return *this; 
}

int CTimeSpan::getIGio () const{
    return iGio;
}
int CTimeSpan::getIPhut() const{
    return iPhut;
}
int CTimeSpan::getIGiay()const{
    return iGiay;
}

void CTimeSpan::setIGio(int gio){
    iGio = gio;
}
void CTimeSpan::setIPhut(int phut){
    iPhut = phut;
}
void CTimeSpan::setIGiay(int giay){
    iGiay = giay;
}


// viết hàm cho CTime

ostream& operator <<(ostream& os, CTime This){
    if(This.iGio < 0 || This.iPhut <0 || This.iGiay < 0){
        cout <<"error"<<endl;
        return os;
    }
    os << This.iGio << ":" << This.iPhut << ":" << This.iGiay << endl;
    return os;
}

istream& operator >> (istream& is, CTime& This){
    is >> This.iGiay >> This.iPhut >> This.iGio ;
    while(This.iGiay < 0 || This.iGiay > 59){ 
        cout << "vui long nhap lai giay:";
        is >> This.iGiay;
    }
    while(This.iPhut < 0  || This.iPhut > 59){
        cout << "vui long nhap lai phut:";
        is >> This.iPhut;
    }
    while(This.iGio < 0 || This.iPhut > 23){ 
        cout << "vui long nhap lai gio:";
        is >> This.iGio;
    }
    return is;
} 

CTime CTime::operator+(int giay){
    CTime temp = *this;
    temp.iGiay += giay;
    temp.setTime();

    return temp;
}
    
CTime CTime::operator-(int giay){
    CTime temp = *this;
    temp.iGiay -= giay;
    temp.setTime();

    return temp;
}

CTime CTime::operator+ ( const CTimeSpan& other ){
    CTime temp = *this;
    temp.iGio += other.getIGio();
    temp.iPhut += other.getIPhut();
    temp.iGiay += other.getIGiay();

    temp.setTime();

    return temp;
}

CTimeSpan CTime::operator- (  const CTime& other ){
    CTimeSpan temp(iGiay - other.iGiay,iPhut - other.iPhut , iGio - other.iGio );
    if(temp.During() < 0){
        temp = CTimeSpan(iGiay - other.iGiay + 60, iPhut - other.iPhut + 59, iGio - other.iGio + 23);
    }    
    temp.setTime();
    return temp;
}

CTime CTime::operator++(int){
    CTime temp = * this;
    iGiay += 1;
    this->setTime();
    return temp;
}
CTime CTime::operator++(){
    iGiay += 1;
    this->setTime();
    return *this;
}
CTime CTime::operator--(int){ 
    CTime temp = * this;
    iGiay -= 1;
    this->setTime();
    return temp;
}
CTime CTime::operator--(){
    iGiay -= 1;
    this->setTime();
    return *this;
}

CTime CTime::setTime(){
    CTimeSpan temp(iGiay, iPhut, iGio);

    if(temp.During() < 0){
        temp = CTimeSpan(iGiay + 60, iPhut + 59, iGio + 23);
    }
    temp.setTime();
    if(temp.getIGio() > 23){
        temp.setIGio(temp.getIGio() % 24);
    }
    

    iGiay = temp.getIGiay();
    iPhut = temp.getIPhut();
    iGio = temp.getIGio();

    return *this;
}

