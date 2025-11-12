#include<iostream>
#include <string>
using namespace std;


class ChuongNgai{
protected:
    int* pThuThach;
public:
    virtual void Nhap(){
        cout << "Nhap Chuong ngai "<< endl;
    }
    virtual bool isVuotQua(int* pNguoi) = 0;
    virtual int getTao() = 0 ;
    virtual string getLoai() = 0;
};

class Chong: public ChuongNgai{
    int iQuaTao;
public:
    void Nhap(){
        ChuongNgai::Nhap();
        cout << "Nhap chi so qua tao: ";
        cin >> iQuaTao;

        pThuThach = new int[7];
        for(int i = 0 ; i < 7; i++){
            cout <<"Nhap gia tri do cao tung chong: ";
            cin >> pThuThach[i];
        }
    }
    bool isVuotQua(int* pNguoi){
        for(int i = 0 ; i < 7; i++){
            if(pNguoi[i] <= pThuThach[i]) return false;
        }
        return true;
    }
    int getTao(){
        return iQuaTao;
    }
    string getLoai(){
        return "Chong";
    }
};

class HamNui : public ChuongNgai{
    int iSoCotMoc;
public:
    void Nhap(){
        ChuongNgai::Nhap();
        cout << " Nhap so cot moc: ";
        cin >> iSoCotMoc;
        pThuThach = new int[iSoCotMoc];
        for(int i = 0 ; i < iSoCotMoc; i++){
            cout <<"Nhap gia tri do cao tung ham: ";
            cin >> pThuThach[i];
        }
    }
    bool isVuotQua(int* pNguoi){
        for(int i = 0 ; i < iSoCotMoc; i++){
            if(pNguoi[0] > pThuThach[i]) return false;
        }
        return true;
    }
    int getTao(){ return 0;}
    string getLoai(){
        return "HamNui";
    }       
};


class QuaiVat : public ChuongNgai{
public:
    void Nhap(){
        ChuongNgai::Nhap();

        pThuThach = new int[5];
        for(int i = 0 ; i < 5; i++){
            cout <<"Nhap gia tri suc manh tung dot quai tan cong: ";
            cin >>pThuThach[i];
        }
    }
    bool isVuotQua(int* pNguoi){
        int CountWin = 0 ;
        for(int i = 0 ; i < 5; i++){
            if(pNguoi[i] >pThuThach[i]) CountWin++;
        }
        if(CountWin > 2) return true;
        return false;
    }   
    int getTao(){
        return 0;
    }
    string getLoai(){
        return "QuaiVat";
    }
};




int main(){
    int iSoChuongNgai;
    cout << "Nhap so chuong ngai: ";
    cin >> iSoChuongNgai;
    ChuongNgai** pDanhSach = new ChuongNgai*[iSoChuongNgai];
    for(int i = 0 ; i < iSoChuongNgai;i++){
        cout << "nhap 1 la tao chuong ngai chong, 2 la chuong ngai Ham, 3 la chuong ngai quai vat: ";
        int temp; cin >> temp;
        if(temp == 1) pDanhSach[i] = new Chong;
        else if(temp ==2) pDanhSach[i] = new HamNui;
        else pDanhSach[i] = new QuaiVat;
    
        pDanhSach[i] ->Nhap();
    }

    int pNhayNguoiChoi[7];
    int pChieuCaoNguoiChoi[0];
    int pSucManhNguoiChoi[5];

    for(int i = 0; i < 7;i++){
        cout <<"Nhap kha nang nhay nguoi choi tung man: ";
        cin >> pNhayNguoiChoi[i];
    }


    cout << "Nhap chieu cao nguoi choi";
    cin >>pChieuCaoNguoiChoi[0];

    for(int i = 0; i < 5;i++){
        cout <<"Nhap suc manh nguoi choi tung man: ";
        cin >> pSucManhNguoiChoi[i];
    }

    bool isLayKhoBau = 1;
    for(int i = 0 ; i < iSoChuongNgai;i++){
        if(pDanhSach[i] ->getLoai() == "Chong"){
            for(int i = 0 ; i< 7 ; i++){
                pNhayNguoiChoi[i] += pDanhSach[i] -> getTao();
            }
            isLayKhoBau = pDanhSach[i] ->isVuotQua(pNhayNguoiChoi);
        }
        else if(pDanhSach[i] ->getLoai() == "HamNui"){
            isLayKhoBau = pDanhSach[i] ->isVuotQua(pChieuCaoNguoiChoi);
        }
        else {
            isLayKhoBau = pDanhSach[i] ->isVuotQua(pSucManhNguoiChoi);
        }
    }

    if(isLayKhoBau) cout << "Nguoi choi lay duoc kho bao" << endl;
    else cout <<" khong lay duoc kho bau " << endl;
    return 0;
}