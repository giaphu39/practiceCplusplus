#include<iostream>
#include <string>
using namespace std;

class Tour{
protected:
    int iMa;
    string sTenTour;
    int iSoLuongKhach;
    float fDonGia;
    int iPhiHuongDan;
public:
    virtual void Nhap(){
        cout <<"Nhap vao " << endl;
        cout <<"Ma Tour: ";
        cin >> iMa;
        cout << "Ten Tour: ";
        cin.ignore();
        getline(cin,sTenTour);
        cout << "So luong khach: ";
        cin >> iSoLuongKhach;
        cout <<"Don gia: ";
        cin >> fDonGia;
        cout << "Phi huong dan: ";
        cin >> iPhiHuongDan;
        cin.ignore();
    }
    
    int getPhiHuongDan(){
        return iPhiHuongDan;
    }

    virtual void Xuat(){
        cout <<"Thong tin Tour " << endl;
        cout <<"Ma Tour: ";
        cout << iMa <<endl;
        cout << "Ten Tour: ";
        cout << sTenTour << endl;
        cout << "So luong khach: ";
        cout << iSoLuongKhach << endl;
        cout <<"Don gia: " ;
        cout << fDonGia << endl;
        cout << "Phi huong dan: ";
        cout << iPhiHuongDan <<endl;
        
    }

    virtual float getHeSoTour() = 0;
    float getTongTienTour(){
        return fDonGia * iSoLuongKhach;
    }
    virtual string getLoaiTour()=0;
};

class TourTrongNuoc : public Tour{
    string sThanhPho;
public:
    void Nhap(){
        Tour::Nhap();
        cout << "Thanh Pho: ";
        getline(cin,sThanhPho);
    }

    void Xuat(){
        Tour::Xuat();
        cout << "Thanh Pho: ";
        cout << sThanhPho << endl;
    }
    float getHeSoTour(){
        return 0;
    }
    string getLoaiTour(){
        return "TrongNuoc";
    }
};

class TourNuocNgoai : public Tour{
    string sQuocGia;
    float fHeSoTour;
public:
    void Nhap(){
        Tour::Nhap();
        cout << "Quoc gia: ";
        getline(cin,sQuocGia);
        cout << "He so Tour: ";
        cin >> fHeSoTour;
        cin.ignore();
    }

    void Xuat(){
        Tour::Xuat();
        cout << "Quoc gia: ";
        cout << sQuocGia << endl;
        cout << "He so Tour: ";
        cout << fHeSoTour << endl;
    }
    float getHeSoTour(){
        return fHeSoTour;
    }
    string getLoaiTour(){
        return "NuocNgoai";
    }
};


class NhanVien{
protected:
    int iMaSo;
    string sHoTen;
    string sDiaChi;
    string sSoDienThoai;
public:
    virtual void Nhap(){
        cout << "Nhap vao nhan vien " <<endl;
        cout << "Ma so: ";
        cin >> iMaSo;
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin,sHoTen);
        cout << "Dia chi: ";
        getline(cin,sDiaChi);
        cout << "So dien thoai: ";
        getline(cin,sSoDienThoai);
    }

    virtual void Xuat(){
        cout << "Thong tin nhan vien " <<endl;
        cout << "Ma so: ";
        cout << iMaSo << endl;
        cout << "Ho ten: ";
        cout << sHoTen <<endl;
        cout << "Dia chi: ";
        cout << sDiaChi << endl;
        cout << "So dien thoai: ";
        cout << sSoDienThoai << endl;
    }
    
    virtual float getLuong() = 0 ;
    virtual Tour* getDaDan()=0;
    virtual string getLoai() = 0 ;
};

class NhanVienVanPhong : public NhanVien{
    int iNgach;
    int iBac;
    float fLuongCoBan;
public:
    void Nhap(){
        NhanVien::Nhap();
        cout << "Ngach: ";
        cin >> iNgach;
        cout << "Bac: ";
        cin >>iBac;
        cout << "Luong co ban: ";
        cin >>fLuongCoBan;
        cin.ignore();
    }
    void Xuat(){
        NhanVien::Xuat();
        cout << "Ngach: ";
        cout << iNgach <<endl;
        cout << "Bac: ";
        cout << iBac << endl;
        cout <<"Luong co ban: ";
        cout << fLuongCoBan << endl;
    }

    float getLuong(){
        return 1.0 * iNgach + 1.0 * iBac / 10 * fLuongCoBan;
    }

    Tour* getDaDan(){
        return NULL;
    }

    string getLoai() {return "CongSo";}
};

class HuongDanVien : public NhanVien{
    float fLuongCung;
    int iSoTourDan;
    Tour* DaDan[5];
public:
    void Nhap(){
        NhanVien::Nhap();
        cout << "Luong cung: ";
        cin >> fLuongCung;
        cout <<"So Tour da dan: ";
        cin >> iSoTourDan;
        cin.ignore();
        for(int i = 0  ; i < iSoTourDan; i++){
            cout<< "nhap 1 la loai Tour trong nuoc, 2 la loai Tour nuoc ngoai: ";
            int temp; cin >>temp;
            if(temp == 1) DaDan[i] = new TourTrongNuoc;
            else if(temp == 2) DaDan[i] = new TourNuocNgoai;

            DaDan[i]->Nhap();
        }
        
    }   

    void Xuat(){
        NhanVien::Xuat();
        cout << "Luong cung: ";
        cout << fLuongCung <<endl;
        cout <<"So Tour da dan: ";
        cout << iSoTourDan << endl;
        for(int i = 0  ; i < iSoTourDan; i++){
            DaDan[i]->Xuat();
        }
    }

    float getLuong(){
        float temp = 0;
        for(int i = 0 ; i < iSoTourDan ; i++){
            if(DaDan[i]->getLoaiTour() == "NuocNgoai"){
                temp += DaDan[i]->getHeSoTour() * DaDan[i]->getTongTienTour();
            }
            else{
                temp += DaDan[i]->getTongTienTour();
            }
        }

        return fLuongCung + temp;

    }

    Tour* getDaDan(){
        return NULL;
    }
    string getLoai() {return "HuongDanVien";}
};

class CongTy{
    int iMaThue;
    string sTenCongTy;
    string sDiaChi;
    string sSoDienThoai;
    NhanVien** DanhSachNhanVien;
    Tour** DanhSachTour;
    int iSoLuongNhanVien;
    int iSoLuongTour;
public:
    void Nhap(){
        cout << "Nhap cong ty "<<endl;
        cout << "Ma thue: ";
        cin >> iMaThue;
        cin.ignore();
        cout << "ten cong ty: ";
        getline(cin, sTenCongTy);
        cout <<"dia chi: ";
        getline(cin, sDiaChi);
        cout << "so dien thoai: ";
        getline(cin,sSoDienThoai);

        //thay doi nhap o day
        iSoLuongNhanVien = 4;
        iSoLuongTour =4;

        DanhSachNhanVien = new NhanVien*[iSoLuongNhanVien];
        DanhSachNhanVien[0] = new NhanVienVanPhong;
        DanhSachNhanVien[2] = new HuongDanVien;
        DanhSachNhanVien[1] = new NhanVienVanPhong;
        DanhSachNhanVien[3] = new HuongDanVien;

        DanhSachTour = new Tour*[iSoLuongTour];
        DanhSachTour [0] = new TourTrongNuoc;
        DanhSachTour[1] = new TourNuocNgoai;
        DanhSachTour [2] = new TourTrongNuoc;
        DanhSachTour[3] = new TourNuocNgoai;

        for(int i = 0 ; i < iSoLuongNhanVien;i++){
            DanhSachNhanVien[i] ->Nhap();
        }
        for(int i = 0 ; i < iSoLuongTour ; i++){
            DanhSachTour[i] ->Nhap();
        }
        // DanhSachNhanVien = new NhanVien*[iSoLuongNhanVien];
        // for(int i = 0 ;  i < iSoLuongNhanVien ;i++){
        //     int temp; 
        //     cout <<"nhap 1 la nhan vien van phong, 2 la huong dan vien du lich: ";
        //     cin >> temp;
        //     if(temp == 1) DanhSachNhanVien[i] = new NhanVienVanPhong;
        //     else DanhSachNhanVien[i] = new HuongDanVien;
        //     DanhSachNhanVien[i] -> Nhap();
        // }
        // DanhSachTour = new Tour*[iSoLuongTour];
        // for(int i = 0 ;  i < iSoLuongTour ;i++){
        //     int temp; 
        //     cout <<"nhap 1 la tour trong nuoc, 2 la tour nuoc ngoai: ";
        //     cin >> temp;
        //     if(temp == 1) DanhSachTour[i] = new TourTrongNuoc;
        //     else DanhSachTour[i] = new TourNuocNgoai;
        //     DanhSachTour[i] -> Nhap();
        // }
    }
    void Xuat(){
        cout << "Thong tin cong ty "<<endl;
        cout << "Ma thue: ";
        cout << iMaThue << endl;
        cout << "ten cong ty: ";
        cout << sTenCongTy <<endl;
        cout <<"dia chi: ";
        cout << sDiaChi << endl;
        cout << "so dien thoai: ";
        cout << sSoDienThoai <<endl;

        // for(int i = 0 ;  i < 2 ;i++){
        //     int temp; 
        //     cout <<"nhap 1 la nhan vien van phong, 2 la huong dan vien du lich: ";
        //     DanhSachNhanVien[i] -> Xuat();
        //     cout <<  DanhSachNhanVien[i] ->getLuong() <<endl;
        // }
        // for(int i = 0 ;  i < 2 ;i++){
        //     DanhSachTour[i] -> Xuat();
        //     cout <<DanhSachTour[i] ->getTongTienTour() <<endl;   
        // }
        for(int i = 0 ; i < iSoLuongNhanVien;i++){
            DanhSachNhanVien[i] ->Xuat();
        }
        for(int i = 0 ; i < iSoLuongTour ; i++){
            DanhSachTour[i] ->Xuat();
        }
    }

    void SapXepNhanVienTheoLuong(){
        for(int i = 0 ; i < iSoLuongNhanVien;i++){
            for(int j = 0 ; j < iSoLuongNhanVien ; j++){
                if(DanhSachNhanVien[i] ->getLuong() < DanhSachNhanVien[j] ->getLuong()){
                    NhanVien* temp = DanhSachNhanVien[i];
                    DanhSachNhanVien[i] = DanhSachNhanVien[j];
                    DanhSachNhanVien[j] = temp;
                }
            }
        }
    }

    void GanRoiSapXep(){
        for(int i = 0 ; i < iSoLuongNhanVien;i++){
            if(DanhSachNhanVien[i] ->getLoai() == "HuongDanVien"){
                // DanhSachNhanVien[i] ->getDaDan()[0];
                DanhSachNhanVien[i] ->Nhap(); // viet ham nhap tour moi -> dung vay la sai
            }
        }

        for(int i = 0 ; i < iSoLuongNhanVien;i++){
            if(DanhSachNhanVien[i] ->getLoai() == "HuongDanVien"){
                for(int j = 0 ; j < iSoLuongNhanVien ; j++){
                    if(DanhSachNhanVien[i] ->getLoai() == "HuongDanVien"){
                        if(DanhSachNhanVien[i] ->getLuong() < DanhSachNhanVien[i] ->getLuong()){
                            NhanVien* temp = DanhSachNhanVien[i];
                            DanhSachNhanVien[i] = DanhSachNhanVien[j];
                            DanhSachNhanVien[j] = temp;
                        }
                    }
                }
            }
        }
    }

};






int main(){
    CongTy a;
    a.Nhap();
    a.Xuat();
    return 0;
}