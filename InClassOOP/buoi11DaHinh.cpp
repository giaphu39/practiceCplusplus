#include<iostream>
#include<string>
using namespace std;
#define MAX 100

class NhanVien{
protected:
    string sHoTen;
    string sNgaySinh;
    int luong;
public:
    virtual void Input(){
        getline(cin,sHoTen);
        cin.ignore();
        getline(cin,sNgaySinh);
    }
    void Output(){
        cout << sHoTen <<endl;
        cout << sNgaySinh << endl;
        cout << luong << endl;
    }
    // int tinhLuong();// không nên
    virtual int getLuong() = 0 ;
};


class NhanVienSanXuat: public NhanVien{
private:
    int luongCanBan;
protected:
    int soSanPham;
public:
    void Input(){
        NhanVien::Input();
        cin >> luongCanBan >> soSanPham;
    }
    int tinhLuong(){
        return luongCanBan + soSanPham * 5000;
    }
};

class 

int main(){

    NhanVienSanXuat a;
    a.Input();
    cout << a.tinhLuong();
    // cout << a.getLuong();
    return 0;
}