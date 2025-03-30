
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
void SapXepGiamTheoMASV(SinhVien A[],int n){
    // ý tưởng 3 đưa kiểu char về string và chuyển tiếp về int rồi so sánh đổi chỗ 
    // cách này không tối ưu và đúng nếu mssv có chứa chữ, chứa chữ thì dùng strcmp 
    string s[MAXN];
    int a[MAXN];
    for(int i=0;i<n;i++){
        for(int j=0;A[i].MASV[j]!='\0';j++){
            s[i]+=A[i].MASV[j]; 
        }
        a[i]=stoi(s[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){ // +1 để giảm thiểu số lần lặp tránh lặp trùng
            if(a[i]<a[j]){
                swap(a[i],a[j]); // nhớ phải cập nhật lại vị trí mssv 
                swap(A[i],A[j]);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     // A[i].MASV=stoi(A[i].MASV);
    //     for(int j=0;A[i].MASV[j]!='\0';j++){
    //         A[j]=int(A[j]); // không cần vì mỗi char cũng là số rồi
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         // 2 vòng lặp để chạy sau đó lại so từng kí tự nếu lớn hơn trong vòng lặp=> n^3
    //     }
    // }
}
// ý tưởng: đưa mssv về float rồi so sánh nếu bé hơn thì đổi chỗ  thứ tự A[i], cách 2 là dùng
// 2 dòng for in ra cái nào bé nhẩt nếu đã được in(mark ) thì sẽ không tính
void Xuat(SinhVien A[], int n){
    for(int i=0;i<n;i++){
        cout<<A[i].MASV<<'\t';
        cout<<A[i].HoTen<<'\t'; // thay vì dùng vòng lặp có thể in vậy ra luôn như string
        cout<<A[i].NgaySinh<<'\t';
        A[i].DTB=tinhDTB(A[i].DiemToan,A[i].DiemLy,A[i].DiemHoa);
        cout<<A[i].GioiTinh<<'\t';
        cout<<A[i].DiemToan<<'\t';
        cout<<A[i].DiemLy<<'\t';
        cout<<A[i].DiemHoa<<'\t';   
        cout<<setprecision(3)<<A[i].DTB<<endl;
        // cout<<fixed<<setprecision(3)<<A[i].DTB<<endl; nhớ các dùng fixed
    }

    
}

int main() {
    SinhVien A[MAXN];
    int n;
    Nhap(A, n);
    SapXepGiamTheoMASV(A, n);
    Xuat(A, n);
    return 0;
}
