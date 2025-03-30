// Tất cả các phần tử trên đường chéo chính bằng 1.
// Có tối đa một cột mà các phần tử dưới đường chéo chính có thể nhận giá trị bất kì.
// Ngoài ra, tất cả các phần tử khác có giá trị bằng 0.
#include <iostream>
using namespace std;
#define MAXR 100
#define MAXC 100
#include <string>
void NhapMaTran(double a[][MAXC], int &n, int& m){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
}
// đánh dấu cột đầu bằng gì đó nếu a[i][mark]
bool duongcheo(double a[][MAXC], int n,int m){
    if(n==0 or m==0 or n!=m or n<0 or m<0) return false; // nhớ kiểm tra các trường hợp đặc biệt
    int mark=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==j){
                if(a[i][j]!=1) return false; // sai chỗ này đặt ==0 sai nếu cho !=1 thì sẽ sai
            }
            else{
                if(mark==-1 and a[i][j]!=0){
                    mark=j;
                }
                else {
                    // if(j==mark) continue;
                    if(j!=mark) {
                        if(a[i][j]!=0) return false;
                    }
                }
            }
        }
    }
    return true;
}
string in(double a[][MAXC], int n,int m){
    string ans;
    if(duongcheo(a,n,m)) ans="Yes";
    else ans="No";
    return ans;
}
int main() {
    double a[MAXR][MAXC];
    int n,m;
    NhapMaTran(a, n,m);
    cout<<in(a,n,m);
    return 0;
}
