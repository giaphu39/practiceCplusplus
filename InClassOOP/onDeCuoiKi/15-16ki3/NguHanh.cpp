#include<bits/stdc++.h>
// #include<iostream>
using namespace std;

const int SAT_THUONG_NHAN_VAT = 5;
const int SAT_THUONG_QUAI_THUONG = 3;
const int SAT_THUONG_QUAI_DAU_LINH = 7;
const float HE_SO_TUONG_SINH = 0.1;
const float HE_SO_TUONG_KHAC = 0.2;

class MoHinh{
protected:
    string sHanh;
    int iCapDo;
public:
    virtual void Nhap(){
        cout << "nhap cap do: ";
        cin >> iCapDo;
        cin.ignore(); // quy dinh ket thuc void nhap ma co cin thi ignore lun
    }

    virtual int getSatThuong()=0;

    string getHanh(){
        return sHanh;
    }

    float getHeSoTuongKhac(string other){
        if(sHanh == "Kim"){
            if(other == "Thuy") return HE_SO_TUONG_SINH;
            if(other == "Moc") return HE_SO_TUONG_KHAC;
            if(other == "Hoa") return -1 * HE_SO_TUONG_KHAC;
        }
        else if(sHanh == "Thuy"){
            if(other == "Moc") return HE_SO_TUONG_SINH;
            if(other == "Hoa") return HE_SO_TUONG_KHAC;
            if(other == "Tho") return -1 * HE_SO_TUONG_KHAC;
        }
        else if(sHanh == "Moc"){
            if(other == "Hoa") return HE_SO_TUONG_SINH;
            if(other == "Tho") return HE_SO_TUONG_KHAC;
            if(other == "Kim") return -1 * HE_SO_TUONG_KHAC;
        }
        else if(sHanh == "Hoa"){
            if(other == "Tho") return HE_SO_TUONG_SINH;
            if(other == "Kim") return HE_SO_TUONG_KHAC;
            if(other == "Thuy") return -1 * HE_SO_TUONG_KHAC;
        }
        else if(sHanh == "Tho"){
            if(other == "Kim") return HE_SO_TUONG_SINH;
            if(other == "Thuy") return HE_SO_TUONG_KHAC;
            if(other == "Moc") return -1 * HE_SO_TUONG_KHAC;
        }

        return 0; // khong tuong khac 

    }
};

class NhanVat: public MoHinh{
    string sMonPhai;
public:
    void Nhap(){
        cout << "nhap nhan vat "<< endl;
        MoHinh::Nhap();
        // cin.ignore();
        cout << "Nhap mon Phai: ";
        getline(cin,sMonPhai);
        if(sMonPhai == "ThieuLam" || sMonPhai == "ThienVuongBang") sHanh = "Kim";
        else if(sMonPhai == "NguDocGiao" || sMonPhai == "DuongMon") sHanh = "Moc";
        else if(sMonPhai == "NgaMy" || sMonPhai == "ThuyYenMon") sHanh = "Thuy";
        else if(sMonPhai == "CaiBang" || sMonPhai =="ThienNhanGiao") sHanh = "Hoa";
        else if(sMonPhai == "ConLon" || sMonPhai == "VoDang") sHanh = "Tho";
    }

    int getSatThuong(){
        return iCapDo * SAT_THUONG_NHAN_VAT;
    }
};

class QuaiVat : public MoHinh{
    string sLoaiQuai;
public:
    void Nhap(){
        cout << "Nhap quai" <<endl;
        MoHinh::Nhap();
        cout << "Nhap ngu hanh: ";
        // cin.ignore();
        getline(cin, sHanh);
        
        cout << "Nhap loai quai: ";
        getline(cin,sLoaiQuai);
    }

    int getSatThuong(){
        if(sLoaiQuai == "ThongThuong") return iCapDo * SAT_THUONG_QUAI_THUONG;
        else if(sLoaiQuai == "DauLinh") return iCapDo * SAT_THUONG_QUAI_DAU_LINH;
    }

    // test 
    void Test(){
        cout << sLoaiQuai << endl;
    }
};









int main(){
    int n;
    cout << "Nhap so luong mo hinh can quan ly: ";
    cin >> n;
    MoHinh** DS = new MoHinh*[n];
    
    for(int i = 0 ; i < n; i++){
        int temp;
        cout << "nhap 1 la NhanVat, nhap 2 la QuaiVat: ";
        cin >> temp;
        if(temp == 1){
            DS[i] = new NhanVat;
        }
        if(temp == 2){
            DS[i] = new QuaiVat;
        }

        DS[i] -> Nhap();
    }

    cout << "Phan tu co muc sat thuong cao nhat trong danh sach la phan tu thu: ";
    int MAX = 0;
    int ind = -1;
    for(int i = 0 ; i < n; i++){
        if(DS[i] ->getSatThuong() > MAX){
            MAX = DS[i]->getSatThuong();
            ind = i;
        }
    }
    if(ind == -1 ) cout << "NOTFOUND"<< endl;
    else cout << ind << endl;

    cout << "Nhap vi tri 2 phan tu can so sanh sat thuong tac dong len nhau: ";
    int ind1; int ind2;
    cin >> ind1 >> ind2;

    cout << "Phan tu dau tac dong len phan tu 2 la ";
    cout << DS[ind1] ->getHeSoTuongKhac(DS[ind2]->getHanh()) * DS[ind1]->getSatThuong() +  DS[ind1]->getSatThuong() << endl;

    cout << "Phan tu 2 tac dong len phan tu 1 la ";
    cout << DS[ind2] ->getHeSoTuongKhac(DS[ind1]->getHanh()) * DS[ind2]->getSatThuong() + DS[ind2]->getSatThuong()<< endl;

    // ((QuaiVat*) DS[ind2] ) ->Test();
    dynamic_cast<QuaiVat*>( DS[ind2] )->Test();
    return 0;
}