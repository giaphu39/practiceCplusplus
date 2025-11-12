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
    string sLoaiGiaoDich;
public:

    void Nhap(int loai = 1, bool nhapLoai = 0);
    void Xuat();
    bool TruyVan(int thang, int nam);
    string getLoaiGiaoDich();
    int getMaGiaoDich();
};

class GiaoDichDat: public GiaoDich{
protected:
    char cLoaiDat;
public:
    void Nhap();
    void Xuat();
    float tinhThanhTien();
};

class GiaoDichNhaPho: public GiaoDich{
protected:
    string sLoaiNha;
    string sDiaChi;
public:
    void Nhap();
    void Xuat();
    float tinhThanhTien();
};

class GiaoDichCanHoChungCu: public GiaoDich{
protected:
    string sMaCan;
    int iViTriTang;
public:
    void Nhap();
    void Xuat();
    float tinhThanhTien();
};


class CongTy{
    GiaoDichDat* pDanhSachGiaoDichDat;
    int iSoLuongGiaoDichDat;

public:
    GiaoDichNhaPho* pDanhSachGiaoDichNhaPho;
    int iSoLuongGiaoDichNhaPho;

    GiaoDichCanHoChungCu* pDanhSachGiaoDichCanHoChungCu;
    int iSoLuongGiaoDichCanHoChungCu;


    void nhapDanhSach();
    void nhapDanhSachGiaoDichDat();
    void nhapDanhSachGiaoDichNhaPho();
    void nhapDanhSachGiaoDichCanHoChungCu();

    void tinhTongSoLuong();
    float tinhTrungBinhGiaoDichCanHoChungCu();
    GiaoDichNhaPho& giaoDichCoThanhTienMax();
    bool xuatTheoTruyVanThang12Nam2024();

    void Xuat();

    ~CongTy();
};



int main()
{
    CongTy VAKALAND;
    VAKALAND.nhapDanhSach();
    cout << endl;
    VAKALAND.tinhTongSoLuong();
    cout << endl;
    cout <<"trung binh giao dich chung cu la : " << VAKALAND.tinhTrungBinhGiaoDichCanHoChungCu() <<endl;
    if(!VAKALAND.xuatTheoTruyVanThang12Nam2024()){
        cout << "khong co giao dich trong thang 12 nam 2024";
    }
    cout <<  "giao dich nha pho co thanh tien Max la: " << VAKALAND.giaoDichCoThanhTienMax().getMaGiaoDich() << endl;
}


// viet class Giao dich
void GiaoDich::Nhap(int loai , bool nhapLoai){
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
    if(nhapLoai){
        cout << "vui long nhap loai giao dich: 1 la giao dich dat, 2 la giao dich nha pho, 3 la giao dich can ho chung cu" <<endl;
        while(true){
            cin >> loai;
            if(loai >= 1 && loai <= 3) break;
            cout <<"vui long nhap lai loai giao dich: ";
        }
    }
    if(loai == 1) sLoaiGiaoDich = "GiaoDichDat";
        else if(loai == 2) sLoaiGiaoDich = "GiaoDichNhaPho";
        else sLoaiGiaoDich = "GiaoDichCanHoChungCu";

}

void GiaoDich::Xuat(){
    cout << iMagiaoDich <<" co ngay giao dich "<< sNgayGiaoDich  << " loai giao dich la ";
    cout << sLoaiGiaoDich << endl;
    cout << "gia la "<< iDonGia << " dien tich "<< fDienTich;
}

string GiaoDich:: getLoaiGiaoDich(){
    return sLoaiGiaoDich;
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
    GiaoDich::Nhap(1,0);
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

void GiaoDichDat::Xuat(){
    GiaoDich::Xuat();
    cout << "loai dat giao dich dat la " << cLoaiDat << endl;
}

float GiaoDichDat::tinhThanhTien(){
    if(cLoaiDat == 'A') return 1.0* fDienTich  * iDonGia * 1.5;
    return 1.0 * fDienTich * iDonGia;
}

// viet class giao dich nha pho

void GiaoDichNhaPho:: Nhap(){
    GiaoDich::Nhap(2,0);
    cout << "vui long nhap loai Nha: nhap vao 'cao cap' hay 'thuong' ";
    cin.ignore();
    while(true){
        getline(cin,sLoaiNha);
        if(sLoaiNha == "cao cap" || sLoaiNha == "thuong") break;
        cout << "nhap lai: ";
    }

    cout << "vui long nhap dia chi: ";
    cin.ignore();
    getline(cin, sDiaChi);
}

void GiaoDichNhaPho::Xuat(){
    GiaoDich::Xuat();
    cout << "loai nha " << sLoaiNha << "dia chi "<< sDiaChi <<endl;
}

float GiaoDichNhaPho::tinhThanhTien(){
    if(sLoaiNha == "cao cap") return fDienTich * iDonGia;
    else return fDienTich * iDonGia * HE_SO_NHA_THUONG;
}

// viet class giao dich can ho chung cu

void GiaoDichCanHoChungCu:: Nhap(){
    GiaoDich::Nhap(3,0);
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

void GiaoDichCanHoChungCu::Xuat(){
    GiaoDich::Xuat();
    cout << " ma can " << sMaCan << " vi tri tang "<< iViTriTang << endl;
}

float GiaoDichCanHoChungCu::tinhThanhTien(){
    if(iViTriTang == 1) return fDienTich * iDonGia * HE_SO_TANG1;
    else if(iViTriTang >=15) return fDienTich * iDonGia * HE_SO_TANG15_UP;
    else return fDienTich * iDonGia;
}

//viet class CongTy

void CongTy::nhapDanhSach(){
    nhapDanhSachGiaoDichDat();
    nhapDanhSachGiaoDichNhaPho();
    nhapDanhSachGiaoDichCanHoChungCu();
}

void CongTy::nhapDanhSachGiaoDichDat(){
    cout << "nhap so luong giao dich dat: ";
    while(true){
        cin >> iSoLuongGiaoDichDat;
        if(iSoLuongGiaoDichDat > 0) break;
    }

    pDanhSachGiaoDichDat = new GiaoDichDat[iSoLuongGiaoDichDat];
    for(int i = 0; i < iSoLuongGiaoDichDat; i++){
        pDanhSachGiaoDichDat[i].Nhap();
    }

}

void CongTy::nhapDanhSachGiaoDichNhaPho(){
    cout << "nhap so luong giao dich nha pho: ";
    while(true){
        cin >> iSoLuongGiaoDichNhaPho;
        if(iSoLuongGiaoDichNhaPho > 0) break;
    }

    pDanhSachGiaoDichNhaPho = new GiaoDichNhaPho[iSoLuongGiaoDichNhaPho];
    for(int i = 0; i < iSoLuongGiaoDichNhaPho ; i++){
        pDanhSachGiaoDichNhaPho[i].Nhap();
    }

}

void CongTy::nhapDanhSachGiaoDichCanHoChungCu(){
    cout << "nhap so luong giao dich can ho chung cu: ";
    while(true){
        cin >> iSoLuongGiaoDichCanHoChungCu;
        if(iSoLuongGiaoDichCanHoChungCu > 0) break;
    }

    pDanhSachGiaoDichCanHoChungCu = new GiaoDichCanHoChungCu [iSoLuongGiaoDichCanHoChungCu];
    for(int i = 0; i < iSoLuongGiaoDichCanHoChungCu ; i++){
        pDanhSachGiaoDichCanHoChungCu[i].Nhap();
    }

}


void CongTy::tinhTongSoLuong(){
    int gdD = 0;
    int gdNP = 0;
    int gdCHCC = 0;
    for(int i = 0 ; i < iSoLuongGiaoDichDat; i++){
        if(pDanhSachGiaoDichDat[i].getLoaiGiaoDich() =="GiaoDichDat") gdD++;
    }
    for(int i =0 ; i < iSoLuongGiaoDichNhaPho ; i++){
        if(pDanhSachGiaoDichNhaPho[i].getLoaiGiaoDich() == "GiaoDichNhaPho") gdNP++;
    }
    for(int i =0 ; i < iSoLuongGiaoDichCanHoChungCu ; i++){
        if(pDanhSachGiaoDichCanHoChungCu[i].getLoaiGiaoDich() == "GiaoDichCanHoChungCu") gdCHCC++;
    }
    cout << " Loai giao dich dat: " << gdD <<endl;
    cout << " Loai giao dich nha pho: " << gdNP << endl;
    cout <<" Loai giao dich can ho chung cu: " << gdCHCC << endl;

}


 float CongTy:: tinhTrungBinhGiaoDichCanHoChungCu(){
    int sumOfThanhTien = 0;
    for(int i = 0 ;i < iSoLuongGiaoDichCanHoChungCu; i++){
        sumOfThanhTien += pDanhSachGiaoDichCanHoChungCu[i].tinhThanhTien();
    }
    return 1.0 * sumOfThanhTien / iSoLuongGiaoDichCanHoChungCu;
 }

GiaoDichNhaPho& CongTy::giaoDichCoThanhTienMax(){
    GiaoDichNhaPho* MAX = pDanhSachGiaoDichNhaPho;
    for(int i = 1; i < iSoLuongGiaoDichNhaPho ; i++){
        if(pDanhSachGiaoDichNhaPho[i].tinhThanhTien() > MAX->tinhThanhTien()){
            MAX = &pDanhSachGiaoDichNhaPho[i];
        }
    }
    return *MAX;
}


bool CongTy::xuatTheoTruyVanThang12Nam2024(){
    cout << "giao dich trong thang 12 nam 2024 la: "<<endl;
    bool truyVanThanhCong = 0;
    for(int i =0 ;i < iSoLuongGiaoDichDat ; i++){
        if(pDanhSachGiaoDichDat[i].TruyVan(12,2024)){
            pDanhSachGiaoDichDat[i].Xuat();
            truyVanThanhCong = 1;
        }
    }

    for(int i =0 ;i < iSoLuongGiaoDichNhaPho ; i++){
        if(pDanhSachGiaoDichNhaPho[i].TruyVan(12,2024)){
            pDanhSachGiaoDichNhaPho[i].Xuat();
            truyVanThanhCong = 1;
        }
    }
    for(int i =0 ;i < iSoLuongGiaoDichCanHoChungCu ; i++){
        if(pDanhSachGiaoDichCanHoChungCu[i].TruyVan(12,2024)){
            pDanhSachGiaoDichCanHoChungCu[i].Xuat();
            truyVanThanhCong = 1;
        }
    }
    return truyVanThanhCong;
}

CongTy::~CongTy(){
    if(!pDanhSachGiaoDichCanHoChungCu){
        delete[] pDanhSachGiaoDichCanHoChungCu;
    }
    if(!pDanhSachGiaoDichDat){
        delete[] pDanhSachGiaoDichDat;
    }
    if(!pDanhSachGiaoDichNhaPho){
        delete[] pDanhSachGiaoDichNhaPho;
    }
}
