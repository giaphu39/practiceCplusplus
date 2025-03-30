#include<iostream>
using namespace std;
// #include<numeric>
// #include<algorithm> // không dùng được gcd
int Gcd(int a, int b){ // Gcd không được viết là gcd vì trùng hàm không dùng được
    if(b == 0) return a;
    else return Gcd(b, a % b);
}

struct PhanSo{
    int tu;
    int mau;
    void nhap()
{
    cin>>tu>>mau;

}
void rutgon(){
    if( tu==0 && mau == 0)
    {
        cout<<"error"; return;
    }
    int ucln= Gcd(abs(tu),abs(mau));
    tu/=ucln;
    mau/=ucln;

    int dau=1;
        if(tu*mau < 0){
            dau = -1;
        }
    tu = abs(tu) * dau;
    mau = abs(mau);
}
void in()
{   
    if( tu==0 && mau == 0)
    {
        return;
    }
    
    if( mau == 0) cout<<"error";
    else if( abs(mau) == 1) cout<< tu;
    else
    {
        cout<< tu  << "/" << mau; 
       
    }
}
};

PhanSo timPhanSomax(const PhanSo& a, const PhanSo &b){
    if(a.tu*b.mau > b.tu * a.mau){
        return a;
    }
    else return b;
}
int main(){
    PhanSo a,b;
    a.nhap(), b.nhap();
    a.rutgon(), b.rutgon();
    timPhanSomax(a,b).in();

    return 0;
}