#include<iostream>
using namespace std;

// hàm nhập khác hàm set không được như nhau liên quan nhau
// không nên lạm dụng operator mà nên làm hàm cộng luôn vì operator dùng friend mà các ngôn ngữ khác không có

// hàm hủy phải trong public



class SoPhuc{
private:
    float fSoThuc;
    float fSoAo;
public:
    SoPhuc(float soThuc = 0, float soAo = 0 ) : fSoThuc(soThuc), fSoAo(soAo){}

    friend SoPhuc operator+(SoPhuc a, SoPhuc b);
    friend SoPhuc operator-(SoPhuc a, SoPhuc b);
    // không nên dùng friend , dùng trong public 1 tham số

    SoPhuc Cong(SoPhuc b){
        SoPhuc c;
        c.fSoThuc = fSoThuc + b.fSoThuc;
        c.fSoAo = fSoAo + b.fSoAo;
    }
    
    void Nhap();
    void In ();
};

    SoPhuc operator+(SoPhuc a, SoPhuc b){
        SoPhuc c(a.fSoThuc + b.fSoThuc, a.fSoAo + b.fSoAo);
        return c;
    }

    SoPhuc operator-(SoPhuc a, SoPhuc b){
        SoPhuc c(a.fSoThuc - b.fSoThuc, a.fSoAo - b.fSoAo);
        return c;
    }

    void SoPhuc::Nhap(){
        cin >> fSoThuc >> fSoAo;
    }

    void SoPhuc::In(){
        cout << fSoThuc <<" phan ao: "<< fSoAo;
    }
int main(){

    SoPhuc a, b;
    a.Nhap();
    b.Nhap();

    (a+b).In();

    return 0;
}