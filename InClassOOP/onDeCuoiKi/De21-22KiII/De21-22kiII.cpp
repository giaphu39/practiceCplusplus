#include<iostream>
#include<string>

using namespace std;

class Sach{
protected:
    string sMaSach;
    string sTenSach;
    string sNhaXuatBan;
    int iSoLuong;
    float fDonGia;
public:
    virtual void Nhap();
    virtual float getThanhTien()=0;
    virtual void Xuat();
    virtual string getNhatXuatBan();
    virtual string getLoaiSach()= 0;
};

class SachGiaoKhoa : public Sach{
    bool bTinhTrang;
public:
    void Nhap();
    float getThanhTien();
    string getLoaiSach();
};

class SachThamKhao : public Sach{
    float fTienThue;
public:
    void Nhap();
    float getThanhTien();
    string getLoaiSach();
};

class ThuVien{
    Sach** pDanhSachSach;
    int iSoLuongLoaiSach;
public:
    void NhapDanhSach();
    void XuatDanhSach();
    void HienThongTinSachCoTienMin();
    void TimThongTinSachGiaoKhoaTheoNhaXuatBan();
};


int main(){
    ThuVien UIT;
    UIT.NhapDanhSach();
    UIT.XuatDanhSach();
    cout << endl;
    UIT.HienThongTinSachCoTienMin();
    cout << endl;
    UIT.TimThongTinSachGiaoKhoaTheoNhaXuatBan();
    return 0;
}


// sach
void Sach:: Nhap(){
    // không nên cho getline ở đầu
    cout << "nhap so luong loai sach nay: ";
    while(true){
        cin >> iSoLuong;
        if(iSoLuong >= 0) break;
        cout << "nhap lai: ";
    }

    cout << "nhap ma sach: ";
    cin.ignore();
    getline(cin,sMaSach);
    cout << "nhap ten Sach: ";
    // cin.ignore(); // sai chỉ khi dùng cin mới dùng ignore
    getline(cin,sTenSach);
    cout << "nhap ten nha xuat ban: ";
    // cin.ignore();
    getline(cin,sNhaXuatBan);

    cout << "nhap don gia( > 0 ): ";
    cin >> fDonGia;

}

void Sach:: Xuat(){
    cout << sTenSach << " voi ma la: "<< sMaSach << endl;
}

string Sach::getNhatXuatBan(){
    return sNhaXuatBan;
}

void SachGiaoKhoa::Nhap(){
    Sach::Nhap();
    cout << "nhap tinh trang 0 la cu , 1 la moi";
    cin >> bTinhTrang;

}

float SachGiaoKhoa::getThanhTien(){
    if(bTinhTrang){
        return iSoLuong * fDonGia;
    }
    return iSoLuong * fDonGia * 0.5;
}

string SachGiaoKhoa::getLoaiSach(){
    return "SachGiaoKhoa";
}

void SachThamKhao::Nhap(){
    Sach::Nhap();
    cout << "nhap tien Thue: (> 0) ";
    cin >> fTienThue;
    
}

float SachThamKhao::getThanhTien(){
    return iSoLuong * fDonGia + fTienThue;
}

string SachThamKhao::getLoaiSach(){
    return "SachThamKhao";
}

void ThuVien::NhapDanhSach(){
    cout << " nhap so luong sach: ";
    cin >> iSoLuongLoaiSach;
    pDanhSachSach = new Sach*[iSoLuongLoaiSach]; // *trước kiểu để trở thành con trỏ

    for(int i = 0 ; i < iSoLuongLoaiSach; i++){
        cout << "nhap 0 la sach Giao Khoa, nhap 1 la sach Tham khoa";
        bool temp; cin >> temp;
        if(temp){
            pDanhSachSach[i] = new SachThamKhao;
            pDanhSachSach[i]->Nhap(); 
        }
        else{
            pDanhSachSach[i] = new SachGiaoKhoa;
            pDanhSachSach[i]->Nhap(); 
        }
    }
}

void ThuVien::XuatDanhSach(){
    for(int i = 0 ; i < iSoLuongLoaiSach; i++){
        pDanhSachSach[i] ->Xuat();
    }
}

void ThuVien::HienThongTinSachCoTienMin(){
    float ThanhTienMin = pDanhSachSach[0]->getThanhTien();

    for(int i = 1 ; i < iSoLuongLoaiSach ; i++){
        if(pDanhSachSach[i]->getThanhTien() < ThanhTienMin){
            ThanhTienMin = pDanhSachSach[i]->getThanhTien();
        }
    }

    for(int i = 0 ; i < iSoLuongLoaiSach; i++){
        if(pDanhSachSach[i]->getThanhTien() == ThanhTienMin){
            pDanhSachSach[i]->Xuat();
        }
    }
}

void ThuVien::TimThongTinSachGiaoKhoaTheoNhaXuatBan(){
    string truyVan;
    getline(cin,truyVan); // co cach nao kiem tra trc khi getline?

    for(int i = 0 ; i < iSoLuongLoaiSach; i++){
        if(pDanhSachSach[i]->getLoaiSach() == "SachGiaoKhoa" && pDanhSachSach[i]->getNhatXuatBan() == truyVan){
            pDanhSachSach[i]->Xuat();
        }
    }


}
