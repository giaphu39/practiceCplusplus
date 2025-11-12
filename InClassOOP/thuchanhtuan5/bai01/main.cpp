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
    float tinhThanhTien();
};

class GiaoDichNhaPho: public GiaoDich{
protected:
    string sLoaiNha;
    string sDiaChi;
public:
    void Nhap();
    float tinhThanhTien();
};

class GiaoDichCanHoChungCu: public GiaoDich{
protected:
    string sMaCan;
    int iViTriTang;
public:
    void Nhap();
    float tinhThanhTien();
};


class CongTy{
public:
    GiaoDichDat* pDanhSachGiaoDichDat;
    int iSoLuongGiaoDichDat;

    GiaoDichNhaPho* pDanhSachGiaoDichNhaPho;
    int iSoLuongGiaoDichNhaPho;

    GiaoDichCanHoChungCu* pDanhSachGiaoDichCanHoChungCu;
    int iSoLuongGiaoDichCanHoChungCu;


    void nhapDanhSach();
    void nhapDanhSachGiaoDichDat();
    void nhapDanhSachGiaoDichNhaPho();
    void nhapDanhSachGiaoDichCanHoChungCu();

    void tinhTongSoLuong();
//    bool truyVanTheoNgay();
    float tinhTrungBinhGiaoDichCanHoChungCu();
    GiaoDichNhaPho& giaoDichCoThanhTienMax();
    bool xuatTheoTruyVanThang12Nam2024();

    void Xuat();
};

int main()
{
    CongTy VAKALAND;
    VAKALAND.nhapDanhSach();
    VAKALAND.xuatTheoTruyVanThang12Nam2024();
//    VAKALAND.Xuat();
}


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
    cout << iMagiaoDich << " co loai giao dich la ";
    cout << sLoaiGiaoDich <<endl;
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
//    int lan = 0;
//    while(true){
//
//        if(sNgayGiaoDich[i++] == '/' && lan == 0){
//            lan++;
//            string temp;
//            while(sNgayGiaoDich[i] != '/'){
//                temp += string() + sNgayGiaoDich[i];
//                i++;
//            }
////            string temp = string() + sNgayGiaoDich[i+1] + sNgayGiaoDich[i+2];
////            char c=    sNgayGiaoDich[i+1];
////            temp+= string()+ sNgayGiaoDich[i+1] + sNgayGiaoDich[i+2]; // thêm str() vì để tránh hiểu lầm là char + char
//            tempThang = stoi(temp);
//            break;
//        }
//        if(sNgayGiaoDich[i] == '/' && lan == 0){
//            string temp;
//            while(sNgayGiaoDich[i] != '\0'){
//                temp += string() + sNgayGiaoDich[i];
//                i++;
//            }
//            tempNam = stoi(temp);
//        }
//        if(sNgayGiaoDich[i] =='\0'){
//            cout <<" error";
//            error = 1;
//            return false;
//        }
//
//        i++;
//    }

    if(tempThang == thang && tempNam == nam) return true;
    return false;
}

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

float GiaoDichDat::tinhThanhTien(){
    if(cLoaiDat == 'A') return 1.0* fDienTich  * iDonGia * 1.5;
    return 1.0 * fDienTich * iDonGia;
}



// viết tiếp 2 loại giao dich còn lại
void GiaoDichNhaPho:: Nhap(){
    GiaoDich::Nhap(2,0);
    cout << "vui long nhap loai Nha: ";
    getline(cin,sLoaiNha);
    cout << "vui long nhap dia chi: ";
    getline(cin, sDiaChi);
}

float GiaoDichNhaPho::tinhThanhTien(){
    if(sLoaiNha == "cao cap") return fDienTich * iDonGia;
    else return fDienTich * iDonGia * HE_SO_NHA_THUONG;
}

void GiaoDichCanHoChungCu:: Nhap(){
    GiaoDich::Nhap(3,0);
    cout << "vui long nhap ma can chung cu: ";
    getline(cin,sMaCan);
    cout << "vui long nhap vi tri tang: ";
    while(true){
        cin >> iViTriTang;
        if(iViTriTang >= 0) break;
    }
}

float GiaoDichCanHoChungCu::tinhThanhTien(){
    if(iViTriTang == 1) return fDienTich * iDonGia * HE_SO_TANG1;
    else if(iViTriTang >=15) return fDienTich * iDonGia * HE_SO_TANG15_UP;
    else return fDienTich * iDonGia;
}



//
//void CongTy::nhapDanhSach(){
//    while(true){
//        cin >> iSoLuong;
//        if(iSoLuong > 0) break;
//        cout << "vui long nhap lai so luong giao dich: ";
//    }
//    pDanhSach = new GiaoDich[iSoLuong];
//
//    for(int i = 0 ; i < iSoLuong ; i++){
//        pDanhSach[i].Nhap();
//    }
//
//}

//void CongTy::Xuat(){
//    for(int i = 0; i < iSoLuong; i++){
////        cout << pDanhSach[i].kiemTraTrongThang12() << " ";
//        cout << pDanhSach[i].getMaGiaoDich() << " la loai " << pDanhSach[i].getLoaiGiaoDich();
//    }
//}

void CongTy::nhapDanhSachGiaoDichDat(){
    while(true){
        cin >> iSoLuongGiaoDichDat;
        if(iSoLuongGiaoDichDat > 0) break;
    }

    pDanhSachGiaoDichDat = new GiaoDichDat[iSoLuongGiaoDichDat];
    for(int i = 0; i < iSoLuongGiaoDichDat; i++){
        pDanhSachGiaoDichDat[i].Nhap();
    }

}

void CongTy::nhapDanhSach(){
    nhapDanhSachGiaoDichDat();
    nhapDanhSachGiaoDichNhaPho();
    nhapDanhSachGiaoDichCanHoChungCu();
}

void CongTy::nhapDanhSachGiaoDichNhaPho(){
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
    while(true){
        cin >> iSoLuongGiaoDichCanHoChungCu;
        if(iSoLuongGiaoDichCanHoChungCu > 0) break;
    }

    pDanhSachGiaoDichCanHoChungCu = new GiaoDichCanHoChungCu [iSoLuongGiaoDichCanHoChungCu];
    for(int i = 0; i < iSoLuongGiaoDichCanHoChungCu ; i++){
        pDanhSachGiaoDichCanHoChungCu[i].Nhap();
    }

}


//void CongTy::tinhTongSoLuong(){
//    int gdD = 0;
//    int gdNP = 0;
//    int gdCHCC = 0;
//    for(int i =0 ;i < iSoLuong ; i++){
//        if(pDanhSach[i].getLoaiGiaoDich() == "GiaoDichDat") gdD++;
//        else if (pDanhSach[i].getLoaiGiaoDich() == "GiaoDichNhaPho") gdNP++;
//        else gdCHCC++;
//    }
//    cout << " Loai giao dich dat: " << gdD <<endl;
//    cout << " Loai giao dich nha pho: " << gdNP << endl;
//    cout <<" Loai giao dich can ho chung cu: " << gdCHCC << endl;
//
//}


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
        if(pDanhSachGiaoDichNhaPho[i].getLoaiGiaoDich() == "GiaoDichCanHoChungCu") gdCHCC++;
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
    for(int i = 0; i< iSoLuongGiaoDichNhaPho ; i++){
        if(MAX->tinhThanhTien() < pDanhSachGiaoDichNhaPho[i].tinhThanhTien()){
            MAX = (pDanhSachGiaoDichNhaPho + i);
        }
    }
    return *MAX;
 }
//bool CongTy::truyVanTheoNgay(){
//    bool truyVanThanhCong = 0;
//    for(int i =0 ;i < iSoLuong ; i++){
//        if(pDanhSach[i].TruyVan(12,2024)){
//            pDanhSach[i].Xuat();
//            truyVanThanhCong = 1;
//        }
//    }
//    return truyVanThanhCong;
//}
bool CongTy::xuatTheoTruyVanThang12Nam2024(){
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

