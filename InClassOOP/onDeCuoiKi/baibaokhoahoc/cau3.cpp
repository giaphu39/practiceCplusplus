#include<bits/stdc++.h>
using namespace std;

class GiaoVien{
    int iMa;
    string sTen;
    string sChuyenNganh;
    string sSDT;
public:
    void Nhap(){
        cout << "nhap vao lan luot la Ma giao vien, ten, chuyen nganh, so dien thoai:   ";
        cin>> iMa;
        cin.ignore();
        getline(cin,sTen);
        getline(cin,sChuyenNganh);
        getline(cin,sSDT);
    }

    int getMa(){
        return iMa;
    }
};


class BaiBao{
protected:
    int iMaBao;
    string sTenBao;
    string sDOI;
    string sNam;
    GiaoVien TacGiaChinh;
    GiaoVien* TacGiaPhu;
    int iSoLuongPhu;
    int iMaDeTai;
public:
    virtual void Nhap(){
        cout << "nhap bao cac thong tin:    ";
        cout << "ma: ";
        cin >> iMaBao;
        cout <<"ten: ";
        cin.ignore();
        getline(cin,sTenBao);
        cout << "DOI: ";
        getline(cin,sDOI);
        cout <<"Nam xuat ban:";
        getline(cin,sNam);
        cout << "so luong tac gia phu: ";
        cin >> iSoLuongPhu;
        cout << "Ma de tai: ";
        cin >> iMaDeTai;
        cin.ignore();
        TacGiaChinh.Nhap();
        TacGiaPhu = new GiaoVien[iSoLuongPhu];
        for(int i = 0 ; i < iSoLuongPhu;i++){
            TacGiaPhu[i].Nhap();
        }


    }

    virtual int getLoai() = 0 ;
    virtual int getTiet(int MaGV) =0;
    int getMa(){
        return iMaDeTai;
    }
};

class TapChi: public BaiBao{
    int iLoai;
public:
    void Nhap(){
        BaiBao::Nhap();
        cout << "Nhap loai bao: 1 la ISI, 2 la Scopus, 3 la Non-Index";
        cin >> iLoai;
        cin.ignore();
        
    }
    int getLoai(){
        return iLoai;
    }
    int getTiet(int MaGV){
        int tiet;
        if(iLoai == 1) tiet = 5000;
        else if(iLoai == 2) tiet = 2500;
        else tiet = 1000;

        if(iMaDeTai){
            tiet *= 0.65; // van la tiet chan
        }
        if(TacGiaChinh.getMa() == MaGV){
            return tiet *= 0.5; // ghi vay duoc khong?
        }
        else{
            for(int i = 0 ; i < iSoLuongPhu;i++){
                if(TacGiaPhu[i].getMa() == MaGV){
                    tiet *= (0.5/iSoLuongPhu);
                    return tiet;
                }
            }
        }

        return 0;
    }
};

class HoiNghi: public BaiBao{
    int iLoai;
public:
    void Nhap(){
        BaiBao::Nhap();
        cout << "Nhap loai: 1 cho core ranking , 2 cho none core ranking ";
        cin >> iLoai;
        cin.ignore();
    }

    int getLoai(){
        return iLoai;
    }

    int getTiet(int MaGV){
        int tiet;
        if(iLoai == 1) tiet = 1000;
        else tiet = 500;
        if(iMaDeTai){
            tiet *= 0.65;
        }
        if(TacGiaChinh.getMa() == MaGV){
            tiet *= 0.5; // ghi vay duoc khong?
            return tiet;
        }
        else{
            for(int i = 0 ; i < iSoLuongPhu;i++){
                if(TacGiaPhu[i].getMa() == MaGV){
                    tiet *= (0.5/iSoLuongPhu);
                    return tiet;
                }
            }
        }
        return 0;
    }
};

class DeTai{
    int iMaDeTai;
    string sTen;
    string sNgay;
    string sThoiGianThucHien;
    int iSoLuongDangKy;
public:
    void Nhap(){
        cout << "nhap noi dung de tai lan luot la ma de tai, ten de tai, ngay , thoi gian thuc hien, ngay nghiem thu, so luong bai bao dang ky:   ";
        cin >> iMaDeTai;
        cin.ignore();
        getline(cin,sTen);
        getline(cin,sNgay);
        getline(cin, sThoiGianThucHien) ;
        cin >> iSoLuongDangKy;
        cin.ignore();
    }
    int getSoLuongDangKy(){
        return iSoLuongDangKy;
    }

    int getMa(){
        return iMaDeTai;
    }
};

// bp sung tyruoc bai bao la giao vien



int main(){
    int n; cout << "so luong bai bao:   ";
    cin >> n;
    cin.ignore();

    BaiBao** ds = new BaiBao*[n];
    for(int i = 0 ; i < n;i++){
        cout << "nhap 1 la tap chi, 2 la hoi nghi:  ";
        int x; cin >> x;
        cin.ignore();

        if(x ==1) ds[i] = new TapChi;
        else ds[i] = new HoiNghi;

        ds[i]->Nhap();
    }


    int n1;cout << "nhap so luong de tai:   "; cin >> n1;
    DeTai* dsdt = new DeTai[n1];
    
    for(int i = 0 ; i < n1; i++){
        dsdt[i].Nhap();
    }

    cout << "nhap ma Giang vien muon tim so tiet:   ";
    int ma; cin >> ma;
    cin.ignore();

    int tongTiet = 0;
    for(int i = 0 ; i < n;i++){
        tongTiet += ds[i]->getTiet(ma);
    }
    cout << "tong so tiet cua giang vien nay la:    ";
    cout << tongTiet << endl;

    cout << "nhap de tai thu may can xet:   ";
    int ind1; cin >> ind1;
    int sldk = dsdt[ind1].getSoLuongDangKy();

    int Count =0;
    for(int i = 0 ; i< n;i++){
        if(ds[i]->getMa() == dsdt[ind1].getMa()){
            Count++;
        }
    }

    if(Count >= sldk) cout << "Du dieu kien nghiem thu\n";
    else cout << "chua du dieu kien nghiem thu\n";
    return 0;
}