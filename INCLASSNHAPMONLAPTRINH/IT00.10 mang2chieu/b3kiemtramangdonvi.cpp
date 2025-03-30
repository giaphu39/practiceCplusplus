
#include <iostream>
using namespace std;
#define MAXR 100
#define MAXC 100

void NhapMaTran(int a[][MAXC], int &n){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
}

bool isMaTranDonVi(int a[][MAXC], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                if(a[i][j]==1) continue;
                else if(a[i][j]!=1) return false;
            }
            else{
                if(a[i][j]!=0) return false;
            }
        }
    }
    return true;
}
// void Xuatmang(int a[][MAXR], int n){ // ghi sai tên hàm và không đồng bộ kiểu dữ liệu của mảng sẽ gây lỗi
//     if (isMaTranDonVi(a,n)) cout<<"true";
//     else cout<<"false";
// }
int main() {
    int a[MAXR][MAXC], n;
    NhapMaTran(a, n);
    std::cout <<  std::boolalpha << isMaTranDonVi(a, n); // hàm boolapha in ra true false chứ không phải 0 1
    return 0;
}


// int main()
// {
//     int n, a[MAX][MAX];
// 	Nhapmang(a,n);
// 	Xuatmang(a,n);
	
//     return 0;
// }