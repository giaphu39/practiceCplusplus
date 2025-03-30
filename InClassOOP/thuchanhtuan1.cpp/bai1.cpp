#include<iostream>
using namespace std;
// #include<numeric>
// #include<algorithm> // không dùng được gcd
int Gcd(int a, int b){ // Gcd không được viết là gcd vì trùng hàm không dùng được

    //cách 2: lấy - nhau cho đến khi =0 thì xong
    if(b == 0) return a;
    else return Gcd(b, a % b);
}

int Gcd2(int a, int b){
    while(a * b != 0){
        if(a > b){
            a %= b;
        }
        else b %= a;
    }

    return a + b;
}
struct PhanSo{
    int tu;
    int mau;

    void nhap();
    void rutgon();
    void in();
    PhanSo timPhanSomax();
    PhanSo tong();
    PhanSo hieu();
    PhanSo tich();
    PhanSo thuong();
};

int main(){
    PhanSo a;
    a.nhap();
    a.rutgon();
    a.in();

    return 0;
}



void PhanSo::nhap()
{
    cin>>tu>>mau;

}
void PhanSo::rutgon(){
    if(mau == 0)
    {
        cout<<"rutgonError"<<endl; 
        return;
    }
    int ucln= Gcd2(abs(tu),abs(mau)); // nhớ lưu trữ biến nếu không thì tu/ucln thì tu thay đổi thì mau sai
    tu/=ucln;
    mau/=ucln;

    int dau=1;
    if(tu*mau < 0){
        dau = -1;
    }
    tu = abs(tu) * dau;
    mau = abs(mau);
}
void PhanSo::in()
{   
    if( mau == 0) cout<<"InError";
    else if( abs(mau) == 1) cout<< tu;
    else
    {
        cout<< tu  << "/" << mau; 
       
    }
}


PhanSo PhanSo::timPhanSomax(const PhanSo& a, const PhanSo &b){
    if(a.tu*b.mau > b.tu * a.mau){
        return a;
    }
    else return b;
}

PhanSo PhanSo::tong(const PhanSo& a, const PhanSo &b){
    PhanSo tong;
    tong.tu = a.tu * b.tu;
    tong.mau = a.mau * b.mau;
}


PhanSo PhanSo::tich(const PhanSo& a, const PhanSo &b){
    PhanSo tich;
    tich.tu = a.tu * b.tu;
    tich.mau = a.mau * b.mau;
}
