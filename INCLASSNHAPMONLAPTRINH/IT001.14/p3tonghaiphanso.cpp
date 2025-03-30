
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
bool lakieuint(float a){
    int b=a;
    if((a-b)==0) return true;
    else return false;
}
//nhớ trường hợp âm nữa
// ý tưởng cứ dùng float + như thường nếu nó là int thì sẽ rút gọn tử mẫu rồi lấy mẫu tử nhân mẫu
string Cong(PhanSo a, PhanSo b){
    string ans;
    float phana=a.tu/a.mau;
    float phanb=b.tu/b.mau;
    float tong= phana+phanb;
    if(lakieuint(tong)) ans+= to_string(int(tong));
    else{
        int uoca= gcd(a.tu,a.mau);
        int uocb= gcd(b.tu,b.mau);
        a.tu/=uoca;a.mau/=uoca;
        b.tu/=uocb;b.mau/=uocb;
        int tutong=((a.tu*b.mau)+(b.tu*a.mau));
        int mautong=(a.mau*b.mau);
        int uocchung=gcd(tutong,mautong);
        // int uocchung=1;
        int dau=-1;
        if((tutong<0 and mautong<0) or (tutong>0 and mautong>0)) dau=1;
        ans+=to_string(dau*abs(tutong)/uocchung)+"/"+to_string(abs(mautong)/uocchung);
    }
    return ans;
}
void Xuat(string s){
    cout<<s;
}

int main() {
    PhanSo a, b;
    Nhap(a);
    b = Nhap();
    Xuat(Cong(a, b));
    // cout<<lakieuint(10000);
    return 0;
}
