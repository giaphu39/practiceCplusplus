


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
    int tu;
    int mau;
    // int uoc=gcd(tu,mau);
};

void Nhap(PhanSo a[], int& n){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].tu;
        cin>>a[i].mau;
    }
}
void Xuat(PhanSo a[], int n){
    string ans[MAXN];
    for(int i=0;i<n;i++){
        int dau=-1;
        int uoc=gcd(a[i].tu,a[i].mau);
        if((a[i].tu<0 and a[i].mau<0) or (a[i].tu>0 and a[i].mau>0)) dau=1;
        if(a[i].mau==0) ans[i]+="Khong thoa yeu cau bai toan";
        else if(a[i].tu % a[i].mau == 0) ans[i]+=to_string((abs(a[i].tu)*dau)/uoc);
        else ans[i]+= to_string(abs(a[i].tu / uoc)*dau) +"/"+ to_string(abs(a[i].mau/ uoc));
        cout<<ans[i]<<endl;
        // cout<<a[i].tu;
    }

}
// ý tưởng: rút gọn phân số bằng ước chung lớn nhất
// #include <iostream>
// using namespace std;
// #include<string.h>
// #define MAXN 300
// int gcd(int a, int b){
//     a=abs(a);
//     b=abs(b);
//     if(b==0) return a;
//     return gcd(b,a%b);
// }
// struct PhanSo{
//     int tu;
//     int mau;
//     string ans[MAXN];
//     int uoc=gcd(tu,mau);
//     int dau=-1;
//     void vietthanh(int i){
//         int dau=-1;
//         int uoc=gcd(tu,mau);
//         if(tu<0 and mau<0) or (tu>0 and mau>0) dau=1;
//         if(mau==0) ans[i]+="Khong thoa yeu cau bai toan";
//         else if(tu % mau == 0) ans+=to_string((abs(tu)*dau)/uoc);
//         else ans+= to_string(abs(tu / uoc)*dau) +"/"+ to_string(abs(mau/ uoc));
//         cout<<ans<<endl;
//     }
    
// };

// void Nhap(PhanSo a[], int& n){
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>a[i].tu;
//         cin>>a[i].mau;
//     }
// }
// void Xuat(PhanSo a[], int n){
//     string ans[MAXN];
//     for(int i=0;i<n;i++){
//         a->vietthanh(i);
//     }
// }

int main() {
    PhanSo a[MAXN];
    int n;
    Nhap(a, n);
    Xuat(a, n);
    return 0;
}

