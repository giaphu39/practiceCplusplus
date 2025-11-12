#include<iostream>
#include <string>
using namespace std;

class Ve{
protected:
    string sHoTenKhachHang;
    string sCMND;
    string sLoaiVe;
    string* sDanhSachTroChoi;
    int iTroChoiDaChoi;
    int iSoDichVuCoBanDaDung;
public:
    virtual void Nhap(){
        cout << "Nhap ten khach hang: ";
        getline(cin,sHoTenKhachHang);
        cout << "Nhap so CMND hoac CCCD: ";
        getline(cin, sCMND);
        cout << "Nhap so tro choi cao cap da choi: ";
        cin >> iTroChoiDaChoi;
        cout << "Nhap so dich vu co ban da dung: ";
        cin >> iSoDichVuCoBanDaDung;
        cin.ignore();
        sDanhSachTroChoi = new string[iTroChoiDaChoi];
        cout << "Nhap tung tro choi da choi: ";
        for(int i = 0; i < iTroChoiDaChoi ;i++){
            getline(cin, sDanhSachTroChoi[i]);
        }
    }

    void Xuat(){
        cout << "ten khach hang: ";
        cout << sHoTenKhachHang << endl;
        cout << "so CMND hoac CCCD: ";
        cout << sCMND << endl;
        cout << "so tro choi cao cap da choi: ";
        cout << iTroChoiDaChoi << endl;
        cout << "so dich vu co ban da dung: ";
        cout << iSoDichVuCoBanDaDung << endl;
        cout << "tung tro choi da choi: ";
        for(int i = 0; i < iTroChoiDaChoi ;i++){
            cout << sDanhSachTroChoi[i] << endl;
        }
    }

    virtual string getLoaiVe() = 0 ;
    int getSoLuotTroChoiCaoCap(){
        return iTroChoiDaChoi;
    }
    
    virtual long long getDoanhThuTuDichVuCoBan() = 0 ;

    virtual ~Ve(){
        if(sDanhSachTroChoi){
            delete[] sDanhSachTroChoi;
        }
    }
};

class VeTronGoi : public Ve{
    int iGiaVe;
public:
    void Nhap(){
        cout << "Nhap thong tin ve tron goi " << endl;
        Ve::Nhap();
        
        iGiaVe = 1500000; 
        sLoaiVe = "VeTronGoi";
    }
    string getLoaiVe(){
        return "VeTronGoi";
    }
    long long getDoanhThuTuDichVuCoBan(){
        return 0;
    }

};


class VeTieuChuan : public Ve{
    int iGiaVeVaoCong;
    int iGiaVeMoiTroChoi;
    int iGiaVeDichVuCoBan;
public:
    void Nhap(){
        cout << "Nhap thong tin ve tieu chuan " << endl;
        Ve::Nhap();

        iGiaVeMoiTroChoi = 150000;
        iGiaVeVaoCong = 400000;
        iGiaVeDichVuCoBan = 0 ;
        sLoaiVe = "VeTieuChuan";
    }
    string getLoaiVe(){
        return "VeTieuChuan";
    }
    long long getDoanhThuTuDichVuCoBan(){
        return 0;
    }

};


class VeKhuyenMai : public Ve{
    int iGiaVeVaoCong;
    int iGiaVeMoiTroChoi;
    int iGiaVeDichVuCoBan;
public:
    void Nhap(){
        cout << "Nhap thong tin ve khuyen mai " << endl;
        Ve::Nhap();

        iGiaVeMoiTroChoi = 200000;
        iGiaVeVaoCong = 0;
        iGiaVeDichVuCoBan = 100000;
        sLoaiVe = "VeKhuyenMai";
    }
    string getLoaiVe(){
        return "VeKhuyenMai";
    }
    long long getDoanhThuTuDichVuCoBan(){
        long long temp = 1;
        return temp * iSoDichVuCoBanDaDung * iGiaVeDichVuCoBan;
    }

};







int main(){
    int n;
    cout << "Nhap so ve ban trong 1 ngay cua cong vien: ";
    cin >> n;

    Ve** CongVien = new Ve*[n];

    for(int i = 0 ; i < n ; i++){
        cout << "nhap 1 la ve tron goi, 2 la ve tieu chuan, 3 la ve khuyen mai: ";
        int temp;
        cin >> temp;
        cin.ignore();
        if(temp == 1) CongVien[i] = new VeTronGoi;
        else if(temp == 2) CongVien[i] = new VeTieuChuan;
        else CongVien[i] = new VeKhuyenMai;

        CongVien[i]->Nhap();
    }

    cout << endl;

    long long llTongDoanhThuTuDichVuCoBan = 0;
    for(int i = 0 ; i < n ; i++){
        llTongDoanhThuTuDichVuCoBan += CongVien[i]->getDoanhThuTuDichVuCoBan();
    }
    cout << "Tong doanh thu tu dich vu co ban la: " << llTongDoanhThuTuDichVuCoBan << endl;


    int CountLuotChoiMax = -1;
    for(int i = 0 ; i < n ; i++){
        if(CongVien[i]->getSoLuotTroChoiCaoCap() > CountLuotChoiMax){
            CountLuotChoiMax = CongVien[i]->getSoLuotTroChoiCaoCap();
        }
    }

    if(CountLuotChoiMax == -1) cout << "Khong co ve nao choi tro choi cao cap" << endl;
    else{
        cout << "Ve co so luot choi tro choi cao cap nhieu nhat la ve "<<endl;
        for(int i = 0 ; i < n ; i++){
            if(CongVien[i]->getSoLuotTroChoiCaoCap() == CountLuotChoiMax){
                cout << "Thu " << i << endl;
                CongVien[i] ->Xuat();
            }
        }
    }


    int CountVeTieuChuan = 0;
    int CountVeKhuyenMai = 0;
    int SoLuotChoiVeTieuChuan = 0;
    int SoLuotChoiVeKhuyenMai = 0;
    for(int i = 0 ; i < n ; i++){
        if(CongVien[i]->getLoaiVe()=="VeTieuChuan"){
            CountVeTieuChuan++;
            SoLuotChoiVeTieuChuan += CongVien[i]->getSoLuotTroChoiCaoCap();
        }
        else if(CongVien[i]->getLoaiVe()=="VeKhuyenMai"){
            CountVeKhuyenMai++;
            SoLuotChoiVeKhuyenMai += CongVien[i]->getSoLuotTroChoiCaoCap();
        }
    }

    cout << "Trung binh so luot choi cao cap ve tieu chuan la: ";
    if(CountVeTieuChuan == 0){
        cout << 0 << endl;
    }
    else{
        cout << 1.0 * SoLuotChoiVeTieuChuan / CountVeTieuChuan << endl;
    }
    

    cout << "Trung binh so luot choi cao cap ve khuyen mai la: ";
    if(CountVeKhuyenMai == 0){
        cout << 0 << endl;
    }
    else{
        cout << 1.0 * SoLuotChoiVeKhuyenMai / CountVeKhuyenMai << endl;
    }

    for(int i = 0 ; i< n;i++){
        delete CongVien[i];
    }
    delete[] CongVien;
    return 0;
}