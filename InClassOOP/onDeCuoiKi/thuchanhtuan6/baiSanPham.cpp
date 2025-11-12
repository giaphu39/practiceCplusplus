#include <iostream>
#include <string>


using namespace std;

class SanPham{
protected:
    int iMaSo;
    string sTieuDe;
    float fGiaBan;

public:
    // virtual string getLoai() = 0;
    virtual void Nhap(){
        cout << " nhap ma so san pham ( > 0 ): ";
        cin >> iMaSo;
        cout << "nhap tieu de san pham: ";
        cin.ignore();
        getline(cin, sTieuDe);
        cout << "nhap gia ban san pham (> 0): ";
        cin >> fGiaBan;
    }
    float getGiaBan(){
        return fGiaBan;
    }
    virtual void Xuat(){
        cout << "Ma so: " << iMaSo << " Tieu de " << sTieuDe << " co gia ban " << fGiaBan << endl;
    }
};


class TranhAnh : public SanPham{
    float fRong;
    float fCao;
    string sTenHoaSi;
public:
    void Nhap(){
        SanPham::Nhap();
        cout << "nhap chieu rọng (>0) : ";
        cin >> fRong;
        cout << "nhap chieu cao (>0) : ";
        cin >> fCao;
        cout << "nhap ten hoa si: ";
        cin.ignore();
        getline(cin,sTenHoaSi);
    }

    void Xuat(){
        SanPham::Xuat();
        cout << " la tranh co chieu rong "<< fRong <<" va chieu cao " << fCao << " ten hoa si " << sTenHoaSi << endl;
    }


};

class CDAmNhac: public SanPham{
    string sTenCaSi;
    string sTenDonViSanXuat;
public:
    void Nhap(){
        SanPham::Nhap();
        cin.ignore();
        cout << " nhap vao ten ca si: ";
        getline(cin , sTenCaSi);

    }

    void Xuat(){
        SanPham::Xuat();
        cout << " ten ca si " << sTenCaSi << " don vi san xuat " << sTenDonViSanXuat << endl;
    }
};

class KhachHang{
    int iMaKhachHang;
    string sTenKhachHang;
    long lSoDienThoai;
public:
    void Nhap(){
        cout << "Nhap ma khach hang: ";
        cin >> iMaKhachHang;
        cout << "Nhap ten khach hang: ";
        cin.ignore();
        getline(cin,sTenKhachHang);
        cout << "Nhap so dien thoai: ";
        cin >> lSoDienThoai;
    }

    int getMaKhachHang(){
        return iMaKhachHang;
    }

    void Xuat(){
        cout << " Ma khach hang " << iMaKhachHang << " ten khach hang " << sTenKhachHang << " so dien thoai " << lSoDienThoai ;
    }
};

class HoaDon{
    string sMaHoaDon;
    KhachHang ThongTin;
    string sNgayLap;
    SanPham** pDanhSachSanPham;
    float fTongGia;
    int iSoLuongSanPham;

public:
    void Nhap(){
        cout << " nhap ma hoa don: ";
        cin >> sMaHoaDon;
        ThongTin.Nhap();
        cin.ignore();
        cout << "Nhap ngay lap: ";
        getline(cin,sNgayLap);
        cout << "Nhap so luong san pham: ";
        cin >> iSoLuongSanPham;
        pDanhSachSanPham = new SanPham*[iSoLuongSanPham];
        for(int i = 0 ; i < iSoLuongSanPham ; i++){
            // cho nay lam bi sai vi khong tao doi tuong
            cout <<"Nhap loai san pham: 0 la TranhAnh , 1 la CD" <<endl;
            int temp;
            cin >> temp;
            if(temp) pDanhSachSanPham[i] = new TranhAnh;
            else pDanhSachSanPham[i] = new CDAmNhac;

            pDanhSachSanPham[i]->Nhap();
        }

        fTongGia = 0;
        for(int i = 0 ; i < iSoLuongSanPham ; i++){
            fTongGia += pDanhSachSanPham[i]->getGiaBan();
        }

    }

    float getTongGia(){
        return fTongGia;
    }

    void Xuat(){
        cout << " Ma hoa don " << sMaHoaDon;
        ThongTin.Xuat();
        cout <<" ngay lap " << sNgayLap;
        cout <<" thong tin cac san pham " << endl;
        for(int i = 0 ; i < iSoLuongSanPham ; i++){
            pDanhSachSanPham[i]->Xuat();
        }
        cout <<" tong gia ban " << fTongGia << endl;
    }

    KhachHang& getKhachHang(){
        return ThongTin;
    }
};
#include <vector>

int main (){
    
    int SoLuongHoaDon;
    cout << "Nhap so luong hoa don: ";
    cin >> SoLuongHoaDon;
    
    HoaDon pDanhSach[SoLuongHoaDon];
    for(int i = 0; i < SoLuongHoaDon ; i++){
        pDanhSach[i].Nhap();
    }

    cout << " xuat danh sach " << endl;

    for(int i = 0; i < SoLuongHoaDon ; i++){
        pDanhSach[i].Xuat();
    }

    float Sum =0;
    cout << "Tong thu nhap la: ";
    for(int i = 0 ; i < SoLuongHoaDon ; i++){
        Sum +=pDanhSach[i].getTongGia();
    }

    cout << Sum << endl;

    float SumMax = 0;
    for(int i = 0  ; i < SoLuongHoaDon; i++){
        float SumTemp = pDanhSach[i].getTongGia();
        int j;
        int target = pDanhSach[i].getKhachHang().getMaKhachHang();
        for( j = i + 1 ;  j < SoLuongHoaDon ; j ++){
            if(target == pDanhSach[j].getKhachHang().getMaKhachHang()){
                SumTemp += pDanhSach[i].getKhachHang().getMaKhachHang();
            }
        }
        if(SumMax < SumTemp) SumMax = SumTemp;

    }
    cout << "Cac khach hang mua nhieu nhat la: "<<endl;
    

    for(int i = 0  ; i < SoLuongHoaDon; i++){
        float SumTemp = pDanhSach[i].getTongGia();
        int j;
        int target = pDanhSach[i].getKhachHang().getMaKhachHang();
        for( j = i + 1 ;  j < SoLuongHoaDon ; j ++){
            if(target == pDanhSach[j].getKhachHang().getMaKhachHang()){
                SumTemp += pDanhSach[i].getKhachHang().getMaKhachHang();
            }
        }
        if(SumMax == SumTemp){
            pDanhSach[i].getKhachHang().Xuat();
        }

    }
    return 0;
}


