// #include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;


class SoHong{
protected:
    string sSoGiay;
    string sTenSoHuu;
    string sNamSinhNguoi;
    string sCMND;
    string sDiaChiNguoi;
    int iSoThuaDat;
    int iSoToBanDo;
    float fDienTich;
    string sNgayCap;
    float fThue;

public:
    virtual void Nhap(){
        cout <<" nhap so giay chung nhan: ";
        getline(cin,sSoGiay);
        cout << "Nhap ten nguoi so huu: ";
        getline(cin,sTenSoHuu);
        cout <<"Nhap nam sinh nguoi: ";
        getline(cin,sNamSinhNguoi);
        cout <<"Nhap CMND: ";
        getline(cin,sCMND);
        cout <<"Nhap dia chi thuong tru: ";
        getline(cin,sDiaChiNguoi);
        cout << "Nhap so thua dat: ";
        cin >> iSoThuaDat;
        cout << "Nhap so to ban do: ";
        cin >> iSoToBanDo;
        cout <<"Nhap dien tich dat: ";
        cin >> fDienTich;
        cout << "nhap ngay cap so: ";
        cin.ignore();
        getline(cin,sNgayCap);
        cout <<"Nhap thue: ";
        cin >> fThue;
        cin.ignore();
    }

    virtual void Xuat(){
        cout <<" so giay chung nhan: " << sSoGiay <<endl;
        cout << " ten nguoi so huu: " << sTenSoHuu<<endl;
        cout <<" nam sinh nguoi: ";
        cout << sNamSinhNguoi <<endl;
        cout <<" CMND: " << sCMND <<endl;
        cout <<" dia chi thuong tru: " << sDiaChiNguoi <<endl;
        cout << " so thua dat: " << iSoThuaDat <<endl;
        cout << " so to ban do: " << iSoToBanDo <<endl;
        cout <<" dien tich dat: " << fDienTich <<endl;
        cout << " ngay cap so: " << sNgayCap <<endl;
        cout <<" thue: " << fThue << endl;

    }

    float getThue(){
        return fThue;
    }
    virtual bool isHetHan(int Nam) = 0;
    virtual string getLoai() = 0;
    virtual int getNam() = 0;
};


class DatNongNghiep : public SoHong {
    int iNamHan;
public:
    void Nhap(){
        SoHong::Nhap();
        cout << "nhap nam han: ";
        cin >> iNamHan ;
        cin.ignore();
    }

    void Xuat(){
        SoHong::Xuat();
        cout <<"Nam Han: "<< iNamHan <<endl;
    }

    bool isHetHan(int Nam){
        return iNamHan < Nam;
    }

    string getLoai(){
        return "DatNongNghiep";
    }

    int getNam(){
        return iNamHan;
    } // khong can

};

class DatPhiNong: public SoHong{

public:
    bool isHetHan(int Nam){
        return false;
    }

    string getLoai(){
        return "DatPhiNong";
    }
    
    int getNam(){
        return 0;
    }
};










int main(){
    int n;
    cout << "Nhap so luong cac giay chung nhan quyen dat: ";
    cin >> n;

    SoHong** DS = new SoHong*[n];
    for(int i = 0 ; i < n ; i++){
        int temp; 
        cout << "Nhap 1 la so hong cho dat nong nghiep, 2 la so hong cho dat phi nong nghiep: ";
        cin >> temp; 
        cin.ignore();
        if(temp == 1) DS[i] = new DatNongNghiep;
        else if(temp == 2) DS[i] = new DatPhiNong;
        DS[i]->Nhap();
    }

    float MAX = 0;
    int ind = -1;
    for(int i = 0 ; i < n ; i++){
        if(DS[i] ->getThue() > MAX){
            MAX = DS[i] ->getThue();
            ind = i;
        }
    }

    cout << "Thua dat co tien thue phai dong nhieu nhat la " << endl;
    DS[ind] ->Xuat();

    int NamHienTai;
    cout <<"Nhap nam hien tai: ";
    cin >>NamHienTai;
    cout << "Thua dat nong nghiep het thoi han dung la " << endl;
    for(int i = 0 ; i < n ; i++){
        if(DS[i] ->isHetHan(NamHienTai) && DS[i] -> getLoai() == "DatNongNghiep"){
            DS[i] ->Xuat();
        }
    }
    return 0;
}