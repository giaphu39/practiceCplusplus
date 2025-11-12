#include<iostream>
#include <string>
using namespace std;


const int HE_SO_TIEN_MOI_BAI_VIET = 200000;
const int HE_SO_TIEN_LUOT_XEM = 500000;
const int HE_SO_TIEN_VIDEO_MOI_PHUT = 50000;
const int HE_SO_TIEN_MOI_CHIEN_DICH = 500000;

class NhanVien{
protected:
    string sHoTen;
    string sMaNhanVien;
    string sNamSinh;
    long lLuongCoBan;
public:
    virtual void Nhap(){
        cout << "Nhap ho ten nhan vien: ";
        getline(cin,sHoTen);
        cout << "Nhap ma nhan vien: ";
        getline(cin , sMaNhanVien);
        cout << "Nhap nam sinh nhan vien: ";
        getline(cin , sNamSinh);
        cout << "Nhap luong co ban: ";
        cin >> lLuongCoBan;
        cin.ignore();
    }

    virtual void Xuat(){
        cout << "ho ten nhan vien: ";
        cout << sHoTen << endl;
        cout << "ma nhan vien: ";
        cout << sMaNhanVien << endl;
        cout << "nam sinh nhan vien: ";
        cout << sNamSinh << endl;
        cout << "luong co ban: ";
        cout << lLuongCoBan << endl;
        
    }

    virtual float getLuong() = 0 ;
    virtual string getLoai() = 0 ; 
    virtual int getSoChienDich() = 0 ; 
    virtual int getSoPhutDungVideo() = 0 ;

};

class BienTapVien : public NhanVien{
    int iSoBaiVietHoanChinh;
    long lTongSoLuotXemBaiViet;
public:
    void Nhap(){
        cout << "Nhap thong tin bien tap vien "<<endl;
        NhanVien::Nhap();
        cout << "Nhap so bai viet hoan chinh: ";
        cin >> iSoBaiVietHoanChinh;
        cout << "Nhap tong so luot xem bai viet: ";
        cin >> lTongSoLuotXemBaiViet;
        cin.ignore();
    }

    void Xuat(){
        cout << "Thong tin bien tap vien "<<endl;
        NhanVien::Xuat();
        cout << "so bai viet hoan chinh: ";
        cout << iSoBaiVietHoanChinh <<endl;
        cout << "tong so luot xem bai viet: ";
        cout << lTongSoLuotXemBaiViet << endl;
    }

    float getLuong(){
        return lLuongCoBan + (iSoBaiVietHoanChinh * HE_SO_TIEN_MOI_BAI_VIET) + (lTongSoLuotXemBaiViet / 10000) * HE_SO_TIEN_LUOT_XEM;
    }

    string getLoai(){
        return "Bien tap vien";
    }

    int getSoChienDich(){return 0;}
    int getSoPhutDungVideo(){return 0;}
};

class NguoiDungVideo : public NhanVien{
    int iSoPhutDungVideo;
public:
    void Nhap(){
        cout << "Nhap thong tin nguoi dung video "<<endl;
        NhanVien::Nhap();
        cout << "Nhap so phut dung video: ";
        cin >> iSoPhutDungVideo;
        cin.ignore();
    }

    void Xuat(){
        cout << "Thong tin nguoi dung video "<<endl;
        NhanVien::Xuat();
        cout << "so phut dung video: ";
        cout << iSoPhutDungVideo << endl;
    }

    float getLuong(){
        return lLuongCoBan + (iSoPhutDungVideo * HE_SO_TIEN_VIDEO_MOI_PHUT);
    }

    string getLoai(){
        return "Nguoi dung video";
    }

    int getSoChienDich(){ return 0;}

    int getSoPhutDungVideo(){
        return iSoPhutDungVideo;
    }

};

class ChuyenVienTruyenThong : public NhanVien{
    int iSoChienDichTruyenThong;
public:
        void Nhap(){
        cout << "Nhap thong tin chuyen vien truyen thong "<<endl;
        NhanVien::Nhap();
        cout << "Nhap so chien dich truyen thong: ";
        cin >> iSoChienDichTruyenThong;
        cin.ignore();
    }

    void Xuat(){
        cout << "Thong tin chuyen vien truyen thong "<<endl;
        NhanVien::Xuat();
        cout << "so chien dich truyen thong: ";
        cout << iSoChienDichTruyenThong <<endl;
    }

    float getLuong(){
        return lLuongCoBan + (iSoChienDichTruyenThong * HE_SO_TIEN_MOI_CHIEN_DICH);
    }

    string getLoai(){
        return "Chuyen vien truyen thong";
    }

    int getSoChienDich(){
        return iSoChienDichTruyenThong;
    }

    int getSoPhutDungVideo(){return 0;}

};









int main(){
    int iSoNhanVien;
    cout << "Nhap so nhan vien: ";
    cin >> iSoNhanVien;
    NhanVien** pCongTy = new NhanVien*[iSoNhanVien];

    for(int i = 0 ; i < iSoNhanVien ; i++){
        cout <<"Nhap 1 la bien tap vien , 2 la nguoi dung video , 3 la chuyen vien truyen thong: ";
        int temp;
        cin >> temp;
        cin.ignore();

        if(temp == 1) pCongTy[i] = new BienTapVien;
        else if(temp == 2)pCongTy[i] = new NguoiDungVideo;
        else pCongTy[i] = new ChuyenVienTruyenThong;

        pCongTy[i] -> Nhap();

    }
    cout << endl;

    long long llTongLuongCanTra = 0 ;
    for(int i = 0 ; i < iSoNhanVien ; i++){
        llTongLuongCanTra += pCongTy[i] ->getLuong();
    }

    cout <<"Tong luong cong ty can tra la: ";
    cout << llTongLuongCanTra << " VNĐ" << endl;

    int iViTriNguoiDungMax = -1;
    int iMaxSoPhutDung = -1;
    for(int i = 0 ; i < iSoNhanVien ; i++){
        if(pCongTy[i] ->getLoai() == "Nguoi dung video"){
            if(pCongTy[i] ->getSoPhutDungVideo() > iMaxSoPhutDung){
                iMaxSoPhutDung = pCongTy[i] ->getSoPhutDungVideo();
                iViTriNguoiDungMax = i;
            }
        }   
    }

    // cout << "Nguoi dung video co tong so phut dung nhieu nhat la nhan vien thu: ";
    if(iViTriNguoiDungMax == -1) cout << "Khong co nhan vien dung video" << endl;
    else{ // neu co chu cac thi phai cho for vong lap lun

        for(int i = 0 ; i <iSoNhanVien ; i++){
            if(pCongTy[i] ->getLoai() == "Nguoi dung video"){
                if(pCongTy[i] ->getSoPhutDungVideo() == iMaxSoPhutDung){
                    cout << "Nguoi dung video co tong so phut dung nhieu nhat la nhan vien thu: ";
                    pCongTy[i] ->Xuat();
                }
            } 
        }
    }


    int iCountSoChuyenVienTruyenThong = 0;
    int iTongSoChienDich = 0;
    for(int i = 0 ; i < iSoNhanVien ; i++){
        if(pCongTy[i] ->getLoai() == "Chuyen vien truyen thong"){
            iCountSoChuyenVienTruyenThong++;
            iTongSoChienDich += pCongTy[i]->getSoChienDich();
        }   
    }
    cout << "Trung binh so chien dich cua chuyen vien truyen thong la: ";
    if(iTongSoChienDich == 0) cout << 0;
    else{
        cout <<  iTongSoChienDich*1.0 / iCountSoChuyenVienTruyenThong <<endl;
    }
   
    
    for(int i = 0 ; i < iSoNhanVien ; i++){
        delete pCongTy[i];
    }
    delete[] pCongTy;


    return 0;
}