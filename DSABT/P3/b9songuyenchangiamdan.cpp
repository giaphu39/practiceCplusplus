/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/



//###INSERT CODE HERE -
#include<iostream>
#define MAXN 100
using namespace std;
int Input(){
    int n;cin>>n;
    return n;
}
void NhapMang(int*a, int& n){
    // cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
void SapXepSoChanGiamDan(int *a, int n){
    for(int i=0;i<n-1;i++){
        if( !(a[i]&1)){
            int iMax=i;
            for(int j=i+1;j<n;j++){
                //sai do dùng a[i] thay vì a[j]
                // if(!(a[i]&1) && a[j]> a[iMax]){
                if(!(a[j]&1) && a[j]> a[iMax]){
                    iMax=j;
                }
            }
            swap(a[i],a[iMax]);
        }
        
    }
}


void XuatMang(int A[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
}
int main() {
    int a[MAXN], n;
    n=Input();
    NhapMang(a, n);
    SapXepSoChanGiamDan(a, n);
    XuatMang(a, n);
    return 0;
}
