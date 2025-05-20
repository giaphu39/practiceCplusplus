#include<iostream>
using namespace std;

class soPhuc{
    float fThuc;
    float fAo;
public:
    // soPhuc(float FThuc,float FAo);
    soPhuc(float FThuc = 0 ,float FAo = 0): fThuc(FThuc), fAo(FAo){}
    
    friend ostream& operator <<(ostream& os, soPhuc This);
    friend istream& operator >> (istream& is, soPhuc& This);

    friend soPhuc operator+(const soPhuc& a, const soPhuc& b);
};


int main(){

    soPhuc a(3,4);
    cout << a;
    soPhuc b;
    cin >> b;
    cout << b;
    cout << a + b;
    // soPhuc c = a + b;
    return 0;
}


// soPhuc::soPhuc(float FThuc = 0 ,float FAo = 0): fThuc(FThuc), fAo(FAo){}

ostream& operator <<(ostream& os, soPhuc This){
    os << This.fThuc << " + " << This.fAo << "i"<<endl;
    return os;
}

istream& operator >> (istream& is, soPhuc& This){
    is >> This.fThuc >> This.fAo ;
    return is;
}

soPhuc operator+(const soPhuc& a, const soPhuc& b){
    soPhuc c;
    c.fThuc = a.fThuc + b.fThuc;
    c.fAo = a.fAo + b.fAo;
    return c;
}

