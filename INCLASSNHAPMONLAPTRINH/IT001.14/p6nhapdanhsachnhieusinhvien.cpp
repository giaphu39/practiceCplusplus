
#include <iomanip>
#include <iostream>
using namespace std;
#define MAXN 100

struct SinhVien {
    string MASV;
    string HoTen;
    string NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};


void Nhap(SinhVien A[], int& n){ // nhớ phải có & vì đây không phải là A[] là con trỏ
    cin>>n;
    for(int i=0;i<n;i++){
        // getline(A[i].MASV,10); // getline chỉ dùng trong string 
        // cin.getline(A[i].HoTen,100); 
        // cin.getline(A[i].NgaySinh,12);
        cin.ignore();// loại bỏ các khoảng /n dư thừa trước đó từ cin>>n
        getline(cin,A[i].MASV); // dùng cho string để không lấy dấu /n
        
        getline(cin,A[i].HoTen);
        getline(cin,A[i].NgaySinh);
        cin>>A[i].GioiTinh;
        cin>>A[i].DiemToan>>A[i].DiemLy>>A[i].DiemHoa;

    }

}
float tinhDTB(float a, float b, float c){
    return ((a+b+c)/3);
}
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
    Xuat(A, n);
    return 0;
}
