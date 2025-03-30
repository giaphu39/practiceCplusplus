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

    
    if( mau == 0){
        cout<<"error"<<endl; return;
    } 
    else if( abs(mau) == 1) cout<< tu;
    else
    {
        cout<< tu  << "/" << mau; 
       
    }
    cout<<endl;
}
friend PhanSo operator+(PhanSo a, PhanSo b){
    PhanSo ans;
    ans.tu = a.tu*b.mau + b.tu * a.mau;
    ans.mau = a.mau * b.mau;
    ans.rutgon();
    return ans;
}

friend PhanSo operator-(PhanSo a, PhanSo b){
    PhanSo ans;
    ans.tu = a.tu*b.mau - b.tu * a.mau;
    ans.mau = a.mau * b.mau;
    ans.rutgon();
    return ans;
}
friend PhanSo operator*(PhanSo a, PhanSo b){
    PhanSo ans;
    ans.tu = a.tu* b.tu;
    ans.mau = a.mau * b.mau;
    ans.rutgon();
    return ans;
}
friend PhanSo operator/(PhanSo a, PhanSo b){
    PhanSo ans;
    ans.tu = a.tu* b.mau;
    ans.mau = a.mau * b.tu;
    ans.rutgon();
    return ans;
}
};

bool isPhanSolonhon(const PhanSo& a, const PhanSo &b){
    if(a.tu*b.mau > b.tu * a.mau){
        return 1;
    }
    else return 0;
}
void Nhaphangloat(PhanSo a[], int n){
    for(int i = 0 ; i < n; i++){
        cin>>a[i].tu>>a[i].mau;
        a[i].rutgon(); // quan trọng nhất là dòng này
    }
}
void Inhangloat(PhanSo a[], int n){
    for(int i = 0 ; i < n; i++){
        a[i].in();
    }
}
void SortPhanSoGiamdan(PhanSo* a , int n){
    for(int i = 0 ; i < n - 1; i++){
        int temp = i;
        for(int j = i + 1; j < n ; j++){
            if(isPhanSolonhon(a[j],a[temp])){
                temp = j;
            }
        }
        swap(a[i] , a[temp]);
    }
}

void SortPhanSoTangdan(PhanSo* a , int n){
    for(int i = 0 ; i < n - 1; i++){
        int temp = i;
        for(int j = i + 1; j < n ; j++){
            if(! isPhanSolonhon(a[j],a[temp])){
                temp = j;
            }
        }
        swap(a[i] , a[temp]);
    }
}
int main(){
    int n; cin >> n;

    PhanSo arr[n];
    Nhaphangloat(arr,n);
    
    // SortPhanSoGiamdan(arr,n);

    // Inhangloat(arr,n);

    SortPhanSoTangdan(arr,n);

    Inhangloat(arr,n);
    arr[n-1].in(); // phân số lớn nhất
    return 0;
}