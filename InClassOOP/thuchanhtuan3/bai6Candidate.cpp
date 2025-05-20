#include<iostream>
#include<string>
using namespace std;

#define MAX 200

class cCandidate{
    int ms;
    string ten;
    int ngay; int thang ; int nam;
    float toan; float van; float anh;

public:
    float tuTinhDiem();
    void nhap();
    void xuat();
};

class  cListCandidate{
    int soThiSinh;
    cCandidate* ds;

public:
    cListCandidate(int SoThiSinh = 0, cCandidate* DS = NULL) : soThiSinh(SoThiSinh), ds(DS){}
    void TongDiemLonHon15();
    cCandidate& thiSinhDiemTBCaoNhat();
    void SapXep();

    void nhap();
    void xuat();
};

int main(){

    cCandidate a; 
    a.nhap();
    a.xuat();
    return 0;
}

void cCandidate::nhap(){
    cin >> ms;
    cin.ignore();
    getline(cin, ten);
    cin >> ngay >> thang >> nam;
    cin >> toan >> van >> anh;
} 

void cCandidate::xuat(){
    cout << ms << " " << ten;
}

float cCandidate::tuTinhDiem(){
    return (toan + van + anh);
}

void cListCandidate::nhap(){
    cin >> soThiSinh;
    ds = new cCandidate[soThiSinh];
    for(int i = 0 ; i < soThiSinh ; i++){
        ds[i].nhap();
    }

}