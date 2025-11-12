#include <iostream>
#include <string>
using namespace std;

#define TIN_CHI_CAO_DANG 110
#define TIN_CHI_DAI_HOC 145
#define DIEM_TRUNG_BINH_TOT_NGHIEP 5
#define DIEM_THI_TOT_NGHIEP 5
#define DIEM_LUAN_VAN_TOT_NGHIEP 5

class SinhVien{
protected:
    int iMaSoSinhVien;
    string sHoTen;
    string sDiaChi;
    int iTongTinChi;
    float fDiemTrungBinh;
public:
    void Nhap();
    void Xuat();
    float getDiemTrungBinh();
    bool isTotNghiep();
    string getHoTen();
};

class SinhVienCaoDang : public SinhVien{
    float fDiemThiTotNghiep;
public:
    void Nhap();
    void Xuat();
    bool isTotNghiep();
    float getDiemThiTotNghiep();
};

class SinhVienDaiHoc : public SinhVien{
    string sTenLuanVan;
    float fDiemLuanVan;
public:
    void Nhap();
    void Xuat();
    bool isTotNghiep();
    float getDiemLuanVan();
};


class Truong{
    SinhVienCaoDang* pDanhSachSinhVienCaoDang;
    SinhVienDaiHoc* pDanhSachSinhVienDaiHoc;
    int iSoLuongSinhVienCaoDang;
    int iSoLuongSinhVienDaiHoc;
public:
    void NhapDanhSachSinhVienCaoDang();
    void NhapDanhSachSinhVienDaiHoc();
    void XuatDanhSachSinhVien();
    void XuatDanhSachSinhVienDuDieuKienTotNghiep();
    void XuatDanhSachSinhVienKhongDuDieuKienTotNghiep();
    SinhVienDaiHoc* sinhVienDiemTrungBinhMAX();

    ~Truong();
};
int main()
{
    Truong DaiHocCongNgheThongTin;
    DaiHocCongNgheThongTin.NhapDanhSachSinhVienCaoDang();
    DaiHocCongNgheThongTin.NhapDanhSachSinhVienDaiHoc();
    cout << endl;
    DaiHocCongNgheThongTin.XuatDanhSachSinhVien();
    cout << endl;
    DaiHocCongNgheThongTin.XuatDanhSachSinhVienDuDieuKienTotNghiep();
    cout <<endl;
    DaiHocCongNgheThongTin.XuatDanhSachSinhVienKhongDuDieuKienTotNghiep();
    cout << endl;
    cout << "sinh vien dai hoc co diem trung binh cao nhat la: ";
    cout << DaiHocCongNgheThongTin.sinhVienDiemTrungBinhMAX()->getHoTen();
    return 0;
}

// viet lop sinh vien

void SinhVien::Nhap(){
    cout << "vui long nhap cac thong tin cua hoc sinh nay " <<endl;
    cout << "Nhap vao ma so Sinh Vien: ";
    while(true){
        cin >> iMaSoSinhVien;
        if(iMaSoSinhVien >= 0) break;
        cout << "nhap lai: ";
    }

    cout << "nhap ho ten: ";
    cin.ignore();
    getline(cin,sHoTen);

    cout << "nhap dia chi: ";
    // cin.ignore(); // đặt ở đây là sai
    getline(cin,sDiaChi);

    cout <<"nhap tong tin chi: ";
    while(true){
        cin >> iTongTinChi;
        if(iTongTinChi >= 0) break;
        cout <<"nhap lai: ";
    }

    cout << "nhap diem trung binh: ";
    while(true){
        cin >> fDiemTrungBinh;
        if(fDiemTrungBinh >=0 && fDiemTrungBinh <= 10)  break;
        cout <<"nhap lai: ";
    }

}

void SinhVien::Xuat(){
    cout << "ma so " << iMaSoSinhVien << " ho ten " << sHoTen << " dia chi " << sDiaChi << " tong tin chi " << iTongTinChi << " diem trung binh " << fDiemTrungBinh;
}

float SinhVien::getDiemTrungBinh(){
    return fDiemTrungBinh;
}

bool SinhVien::isTotNghiep(){
    return fDiemTrungBinh >= DIEM_TRUNG_BINH_TOT_NGHIEP;
}

string SinhVien::getHoTen(){
    return sHoTen;
}

// viết cho sinh vien cao dang

void SinhVienCaoDang::Nhap(){
    SinhVien::Nhap();
    cout << "nhap diem thi tot nghiep: ";
    while(true){
        cin >> fDiemThiTotNghiep;
        if(fDiemThiTotNghiep >= 0 && fDiemThiTotNghiep <= 10) break;
        cout <<"nhap lai: ";
    }
}

void SinhVienCaoDang::Xuat(){
    SinhVien::Xuat();
    cout << " diem thi tot nghiep " << fDiemThiTotNghiep << endl;
}

float SinhVienCaoDang::getDiemThiTotNghiep(){
    return fDiemThiTotNghiep;
}

bool SinhVienCaoDang::isTotNghiep(){
    if(SinhVien::isTotNghiep()){
        return (fDiemThiTotNghiep >= DIEM_THI_TOT_NGHIEP && iTongTinChi >= TIN_CHI_CAO_DANG);
    }
    return false;
}

// viet cho sinh vien dai hoc

void SinhVienDaiHoc::Nhap(){
    SinhVien::Nhap();
    cout << "nhap ten luan van: ";
    cin.ignore();
    getline(cin,sTenLuanVan);

    cout << "nhap diem luan van: ";
    while(true){
        cin >> fDiemLuanVan;
        if(fDiemLuanVan >=0 && fDiemLuanVan <= 10) break;
        cout <<"nhap lai:";
    }
}

void SinhVienDaiHoc::Xuat(){
    SinhVien::Xuat();
    cout << " luan van " << sTenLuanVan << " co diem " << fDiemLuanVan << endl;
}

float SinhVienDaiHoc::getDiemLuanVan(){
    return fDiemLuanVan;
}

bool SinhVienDaiHoc::isTotNghiep(){
    if(SinhVien::isTotNghiep()){
        return (fDiemLuanVan >= DIEM_LUAN_VAN_TOT_NGHIEP && iTongTinChi >= TIN_CHI_DAI_HOC);
    }
    return false;
}

// viet cho Truong Dai Hoc

void Truong::NhapDanhSachSinhVienCaoDang(){
    cout << "nhap so luong sinh vien cao dang: ";
    while(true){
        cin >> iSoLuongSinhVienCaoDang;
        if(iSoLuongSinhVienCaoDang >= 1) break;
        cout << "vui long nhap lai: " ;
    }

    pDanhSachSinhVienCaoDang = new SinhVienCaoDang[iSoLuongSinhVienCaoDang];
    for(int i = 0 ; i < iSoLuongSinhVienCaoDang ; i++){
        pDanhSachSinhVienCaoDang[i].Nhap();
    }

}

void Truong::NhapDanhSachSinhVienDaiHoc(){
    cout << "nhap so luong sinh vien Dai hoc: ";
    while(true){
        cin >> iSoLuongSinhVienDaiHoc;
        if(iSoLuongSinhVienDaiHoc >= 1) break;
        cout << "vui long nhap lai: " ;
    }

    pDanhSachSinhVienDaiHoc = new SinhVienDaiHoc[iSoLuongSinhVienDaiHoc];
    for(int i = 0 ; i < iSoLuongSinhVienDaiHoc ; i++){
        pDanhSachSinhVienDaiHoc[i].Nhap();
    }

}

void Truong::XuatDanhSachSinhVien(){
    cout << "danh sach sinh vien cua truong la: " <<endl;
    for(int i = 0 ; i < iSoLuongSinhVienCaoDang ; i++){
        pDanhSachSinhVienCaoDang[i].Xuat();
    }

    for(int i = 0  ; i < iSoLuongSinhVienDaiHoc ; i++){
        pDanhSachSinhVienDaiHoc[i].Xuat();
    }
}

void Truong::XuatDanhSachSinhVienDuDieuKienTotNghiep(){
    cout << "danh sach sinh vien tot nghiep cua truong la: " <<endl;
    for(int i = 0 ; i < iSoLuongSinhVienCaoDang ; i++){
        if(pDanhSachSinhVienCaoDang[i].isTotNghiep()){
            pDanhSachSinhVienCaoDang[i].Xuat();
        }
    }

    for(int i = 0  ; i < iSoLuongSinhVienDaiHoc ; i++){
        if(pDanhSachSinhVienDaiHoc[i].isTotNghiep()){
            pDanhSachSinhVienDaiHoc[i].Xuat();
        }
    }
}


void Truong::XuatDanhSachSinhVienKhongDuDieuKienTotNghiep(){
    cout << "danh sach sinh vien khong du dieu kien tot nghiep cua truong la: " <<endl;
    for(int i = 0 ; i < iSoLuongSinhVienCaoDang ; i++){
        if(!pDanhSachSinhVienCaoDang[i].isTotNghiep()){
            pDanhSachSinhVienCaoDang[i].Xuat();
        }
    }

    for(int i = 0  ; i < iSoLuongSinhVienDaiHoc ; i++){
        if(!pDanhSachSinhVienDaiHoc[i].isTotNghiep()){
            pDanhSachSinhVienDaiHoc[i].Xuat();
        }
    }
}

SinhVienDaiHoc* Truong::sinhVienDiemTrungBinhMAX(){

    SinhVienDaiHoc* MAX = pDanhSachSinhVienDaiHoc;
    for(int i = 0  ; i < iSoLuongSinhVienDaiHoc ; i++){
        if(MAX->getDiemTrungBinh() < (pDanhSachSinhVienDaiHoc + i)->getDiemTrungBinh()){
            MAX = pDanhSachSinhVienDaiHoc + i;
        }
    }
    return MAX;
}

Truong::~Truong(){
    if(pDanhSachSinhVienCaoDang != NULL){
        delete[] pDanhSachSinhVienCaoDang;
    }
    if(pDanhSachSinhVienDaiHoc != NULL){
        delete[] pDanhSachSinhVienDaiHoc;
    }
}
