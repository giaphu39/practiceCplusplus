#include <iostream>
#include<string>
#include<vector>

using namespace std;
#define HE_SO_NHA_THUONG 0.9
#define HE_SO_TANG1 2.0
#define HE_SO_TANG15_UP 1.2

class GiaoDich{
protected:

    int iMagiaoDich;
    string sNgayGiaoDich;
    int iDonGia;
    float fDienTich;

public:

    virtual void Nhap();
    virtual void Xuat();
    virtual bool TruyVan(int thang, int nam);
    virtual string getLoaiGiaoDich() = 0;
    int getMaGiaoDich();

    virtual float tinhThanhTien()=0;

};

class GiaoDichDat: public GiaoDich{
protected:
    char cLoaiDat;
public:
    void Nhap();
    float tinhThanhTien();
    string getLoaiGiaoDich();
};

class GiaoDichNhaPho: public GiaoDich{
protected:
    string sLoaiNha;
    string sDiaChi;
public:
    void Nhap();
    float tinhThanhTien();
    string getLoaiGiaoDich();
};

class GiaoDichCanHoChungCu: public GiaoDich{
protected:
    string sMaCan;
    int iViTriTang;
public:
    void Nhap();
    float tinhThanhTien();
    string getLoaiGiaoDich();
};


class CongTy{
    GiaoDich** pDanhSach;
    int iSoLuongGiaoDich;
public:


    void nhapDanhSach();

    void tinhTongSoLuong();
    float tinhTrungBinhGiaoDichCanHoChungCu();
    GiaoDich* giaoDichNhaPhoCoThanhTienMax();
    bool xuatTheoTruyVanThang12Nam2024();

    void Xuat();

    ~CongTy();
};



int main()
{
    CongTy VAKALAND;
    VAKALAND.nhapDanhSach();
    VAKALAND.tinhTongSoLuong();
    cout << endl;
    cout <<"trung binh giao dich chung cu la : " << VAKALAND.tinhTrungBinhGiaoDichCanHoChungCu() <<endl;
    if(!VAKALAND.xuatTheoTruyVanThang12Nam2024()){
        cout << "khong co giao dich trong thang 12 nam 2024";
    }
    cout <<  "giao dich co thanh tien Max la: ";
    VAKALAND.giaoDichNhaPhoCoThanhTienMax()->Xuat();
}


// viet class Giao dich
void GiaoDich::Nhap(){ // co nhap loai
    cout << "nhap ma giao dich:";
    cin >> iMagiaoDich;
    cin.ignore();
    cout << "nhap ngay theo format DD/MM/YYYY: ";
    getline(cin,sNgayGiaoDich);

    cout <<"nhap don gia:";
    while(true){
        cin >> iDonGia;
        if(iDonGia > 0) break;
        cout << "vui long nhap lai don gia: ";
    }
    cout <<"nhap dien tich:";
    while(true){
        cin >> fDienTich;
        if(fDienTich > 0) break;
        cout << "vui long nhap lai dien tich: ";
    }

}

void GiaoDich::Xuat(){
    cout <<"giao dich so: " << iMagiaoDich <<endl;

}


int GiaoDich::getMaGiaoDich(){
    return iMagiaoDich;
}

bool GiaoDich::TruyVan(int thang, int nam){
    int tempThang = stoi(string() + sNgayGiaoDich[3] + sNgayGiaoDich[4]);
    int tempNam = stoi(string() + sNgayGiaoDich[6] + sNgayGiaoDich[7] +  sNgayGiaoDich[8] +  sNgayGiaoDich[9]);
    if(tempThang == thang && tempNam == nam) return true;
    return false;
}

// viet class giao dich dat
void GiaoDichDat::Nhap(){
    GiaoDich::Nhap();
    cin.ignore();
    cout <<"nhap loai Dat: A , B , C" <<endl;
    while(true){
        char temp; cin >> temp;
        if(temp>='A' && temp <='C'){
            cLoaiDat = temp;
            break;
        }
        cout <<" vui long nhap lai: ";
    }
}

float GiaoDichDat::tinhThanhTien(){
    if(cLoaiDat == 'A') return 1.0* fDienTich  * iDonGia * 1.5;
    return 1.0 * fDienTich * iDonGia;
}

string GiaoDichDat:: getLoaiGiaoDich(){
    return "GiaoDichDat";
}
// viet class giao dich nha pho

void GiaoDichNhaPho:: Nhap(){
    GiaoDich::Nhap();
    cout << "vui long nhap loai Nha: nhap vao 'cao cap' hay 'thuong' ";
    cin.ignore();
    while(true){
        getline(cin,sLoaiNha);
        if(sLoaiNha == "cao cap" || sLoaiNha == "thuong") break;
        cout << "nhap lai: ";
    }

    cout << "vui long nhap dia chi: ";
    getline(cin, sDiaChi);
}

float GiaoDichNhaPho::tinhThanhTien(){
    if(sLoaiNha == "cao cap") return fDienTich * iDonGia;
    else return fDienTich * iDonGia * HE_SO_NHA_THUONG;
}

string GiaoDichNhaPho:: getLoaiGiaoDich(){
    return "GiaoDichNhaPho";
}
// viet class giao dich can ho chung cu

void GiaoDichCanHoChungCu:: Nhap(){
    GiaoDich::Nhap();
    cout << "vui long nhap ma can chung cu: ";
    cin.ignore();
    getline(cin,sMaCan);
    cout << "vui long nhap vi tri tang: ";
    while(true){
        cin >> iViTriTang;
        if(iViTriTang >= 0) break;
        cout << "nhap lai: ";
    }
}

float GiaoDichCanHoChungCu::tinhThanhTien(){
    if(iViTriTang == 1) return fDienTich * iDonGia * HE_SO_TANG1;
    else if(iViTriTang >=15) return fDienTich * iDonGia * HE_SO_TANG15_UP;
    else return fDienTich * iDonGia;
}

string GiaoDichCanHoChungCu:: getLoaiGiaoDich(){
    return "GiaoDichCanHoChungCu";
}
//viet class CongTy

void CongTy::nhapDanhSach(){
     cout << "nhap so luong giao dich: ";
    while(true){
        cin >> iSoLuongGiaoDich;
        if(iSoLuongGiaoDich > 0) break;
    }

    pDanhSach = new GiaoDich*[iSoLuongGiaoDich];
    for(int i = 0; i < iSoLuongGiaoDich; i++){
        cout << "nhap loai giao dich 1 la giao dich Dat, 2 la giao dich nha pho, 3 la giao dich can ho chung cu: ";
        int temp;
        cin >> temp;
        if(temp == 1){
            pDanhSach[i] = new GiaoDichDat;
        }
        else if(temp == 2){
            pDanhSach[i] = new GiaoDichNhaPho;
        }
        else pDanhSach[i] = new GiaoDichCanHoChungCu;

        pDanhSach[i]->Nhap();
    }
}

void CongTy::tinhTongSoLuong(){
    int gdD = 0;
    int gdNP = 0;
    int gdCHCC = 0;
    for(int i = 0 ; i < iSoLuongGiaoDich; i++){
        if(pDanhSach[i]->getLoaiGiaoDich() =="GiaoDichDat") gdD++;
        if(pDanhSach[i]->getLoaiGiaoDich() == "GiaoDichNhaPho") gdNP++;
        if(pDanhSach[i]->getLoaiGiaoDich() == "GiaoDichCanHoChungCu") gdCHCC++;

    }
    cout << " Loai giao dich dat: " << gdD <<endl;
    cout << " Loai giao dich nha pho: " << gdNP << endl;
    cout <<" Loai giao dich can ho chung cu: " << gdCHCC << endl;

}

 float CongTy:: tinhTrungBinhGiaoDichCanHoChungCu(){
    int sumOfThanhTien = 0;
    int CountOfGiaoDichCanHoChungCu = 0;
    for(int i = 0 ;i < iSoLuongGiaoDich; i++){
        if(pDanhSach[i]->getLoaiGiaoDich() == "GiaoDichCanHoChungCu"){
            sumOfThanhTien += pDanhSach[i]->tinhThanhTien();
            CountOfGiaoDichCanHoChungCu++;
        }
        
    }
    return 1.0 * sumOfThanhTien / CountOfGiaoDichCanHoChungCu;
 }

GiaoDich* CongTy::giaoDichNhaPhoCoThanhTienMax(){
    GiaoDich* MAX = NULL;
    for(int i = 0; i < iSoLuongGiaoDich ; i++){
        if(pDanhSach[i]->getLoaiGiaoDich() == "GiaoDichNhaPho"){
            if(MAX == NULL){
                MAX = pDanhSach[i];
            }
            else if(pDanhSach[i]->tinhThanhTien() > MAX->tinhThanhTien()){
                MAX = pDanhSach[i];
            }
        }
    }
    return MAX;
}


bool CongTy::xuatTheoTruyVanThang12Nam2024(){
    cout << "giao dich trong thang 12 nam 2024 la: "<<endl;
    bool isTruyVanThanhCong = 0;
    for(int i =0 ;i < iSoLuongGiaoDich ; i++){
        if(pDanhSach[i]->TruyVan(12,2024)){
            pDanhSach[i]->Xuat();
            isTruyVanThanhCong = 1;
        }
    }

    return isTruyVanThanhCong;
}

CongTy::~CongTy(){
    for(int i = 0 ; i < iSoLuongGiaoDich; i++){
        if(pDanhSach[i] != NULL){
            delete pDanhSach[i];
        }
    }
    delete[] pDanhSach;
}
