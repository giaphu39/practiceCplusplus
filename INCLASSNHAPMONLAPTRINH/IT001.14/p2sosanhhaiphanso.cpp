


// ý tưởng: rút gọn phân số bằng ước chung lớn nhất
#include <iostream>
using namespace std;
#include<string.h>
#define MAXN 300
int gcd(int a, int b){
    a=abs(a);
    b=abs(b);
    if(b==0) return a;
    return gcd(b,a%b);
}
struct PhanSo{
    float tu;
    float mau;
};

void Nhap(PhanSo& a){
    cin>>a.tu;
    cin>>a.mau;
}
PhanSo Nhap(){
    PhanSo a;
    cin>>a.tu;
    cin>>a.mau;
    return a; 
};

int SoSanh(PhanSo a, PhanSo b){
    if((a.tu/a.mau) == (b.tu/b.mau)) return 0;
    else if((a.tu/a.mau) > (b.tu/b.mau)) return 1;
    else if((a.tu/a.mau) < (b.tu/b.mau)) return -1;
}

int main() {
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    int kq = SoSanh(a, b);
    if (kq == 0)
        std::cout << "Hai phan so bang nhau.";
    else if (kq > 0)
        std::cout << "Phan so thu nhat LON hon phan so thu hai.";
    else
        std::cout << "Phan so thu nhat NHO hon phan so thu hai.";
    return 0;
}
