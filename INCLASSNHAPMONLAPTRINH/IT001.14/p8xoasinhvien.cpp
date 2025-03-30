
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 100

struct SinhVien {
    char MASV[10];
    char HoTen[100];
    char NgaySinh[12];
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};



void Nhap(char a[]){
    cin.getline(a,100);
}
void Nhap(SinhVien A[], int& n){ // nhớ phải có & vì đây không phải là A[] là con trỏ
    cin>>n;
    for(int i=0;i<n;i++){
        cin.ignore();
        cin.getline(A[i].MASV,10); // getline chỉ dùng trong string 
        cin.getline(A[i].HoTen,100); 
        cin.getline(A[i].NgaySinh,12);
        // cin.ignore();// loại bỏ các khoảng /n dư thừa trước đó từ cin>>n
        // getline(cin,A[i].MASV); // dùng cho string để không lấy dấu /n
        
        // getline(cin,A[i].HoTen);
        // getline(cin,A[i].NgaySinh);
        cin>>A[i].GioiTinh;
        cin>>A[i].DiemToan>>A[i].DiemLy>>A[i].DiemHoa;

    }

}
float tinhDTB(float a, float b, float c){
    return ((a+b+c)/3);
}
void XoaTheoHoTen(SinhVien A[],int& n,char hoTenCanXoa[]){
    for(int i=0;i<n;i++){
        if(strcmp(A[i].HoTen,hoTenCanXoa)==0){
            for(int j=i;j<n;j++){
                // cout<<A[i].GioiTinh<<" "<<A[i+1].GioiTinh;
                // A[i]=A[i+1]; //Hong khong xuat hiẹn tiep? // do i đã chạy sang ô tiếp theo
                // sai do dùng chỉ số A[j] mà dùng A[i]
                A[j]=A[j+1]; //debug mất gần 1 h chỉ vì dòng này
            }
            n--;
            i--; // phải làm vậy để nó không chạy sang ô tiếp theo nếu bị xoá
        }
    }
}
void Xuat(SinhVien A[], int n){
    for(int i=0;i<n;i++){
        cout<<A[i].MASV<<'\t';
        cout<<A[i].HoTen<<'\t';
        cout<<A[i].NgaySinh<<'\t';
        A[i].DTB=tinhDTB(A[i].DiemToan,A[i].DiemLy,A[i].DiemHoa);
        cout<<A[i].GioiTinh<<'\t';
        cout<<A[i].DiemToan<<'\t';
        cout<<A[i].DiemLy<<'\t';
        cout<<A[i].DiemHoa<<'\t';   
        cout<<setprecision(3)<<A[i].DTB<<endl;
    }

    
}



int main() {
    SinhVien A[MAXN];
    char hoTenCanXoa[100];
    int n;

    Nhap(hoTenCanXoa);

    Nhap(A, n);

    XoaTheoHoTen(A, n, hoTenCanXoa);

    Xuat(A, n);
    return 0;
}
