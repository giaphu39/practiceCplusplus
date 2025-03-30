
#include <iomanip>
#include <iostream>
#include <stdio.h>
using namespace std;

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
void Nhap(SinhVien& A){ // nhớ phải có & vì đây không phải là A[] là con trỏ
    // fgets(A.MASV,11,stdin);
    // fgets(A.HoTen,101,stdin);
    // fgets(A.NgaySinh,13,stdin);
    cin.getline(A.MASV,10); // getline chỉ dùng trong string 
    cin.getline(A.HoTen,100); // cin.getline này dùng cho kiểu char và không lấy dấu /n
    cin.getline(A.NgaySinh,12);
    cin>>A.GioiTinh;
    cin>>A.DiemToan>>A.DiemLy>>A.DiemHoa;

}
float tinhDTB(float a, float b, float c){
    return ((a+b+c)/3);
}
void Xuat(SinhVien A){
    
    // for(int i=0;A.MASV[i]!='\0';i++){
    //     if(A.MASV[i]=='\n') break;
    //     cout<<A.MASV[i];
    // }
    cout<<A.MASV;
    cout<<'\t';
    // for(int i=0;A.HoTen[i]!='\0';i++){
    //     if(A.MASV[i]=='\n') break;
    //     cout<<A.HoTen[i];
    // }
    cout<<A.HoTen; // thay vì dùng vòng lặp có thể in vậy ra luôn như string
    cout<<'\t';
    // for(int i=0;A.NgaySinh[i]!='\0';i++){
    //     if(A.MASV[i]=='\n') break;
    //     cout<<A.NgaySinh[i];
    // }
    cout<<A.NgaySinh;
    A.DTB=tinhDTB(A.DiemToan,A.DiemLy,A.DiemHoa);
    cout<<'\t';
    cout<<A.GioiTinh<<'\t';
    cout<<A.DiemToan<<'\t';
    cout<<A.DiemLy<<'\t';
    cout<<A.DiemHoa<<'\t';

    cout<<setprecision(3)<<A.DTB;
}

int main() {
    SinhVien A;
    Nhap(A);
    Xuat(A);
    return 0;
}
