/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


//###INSERT CODE HERE -

#include<iostream>
#define MAXN 100
using namespace std;
void NhapMang(int*a, int& n){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
void SapXepSoAmTangDan(int *a, int n){
    for(int i=0;i<n-1;i++){
        if(a[i] < 0){
            int iMin=i;
            for(int j=i+1;j<n;j++){
                if(a[j] < 0 && a[j]< a[iMin]){
                    iMin=j;
                }
            }
            swap(a[i],a[iMin]);
        }
        
    }
}
void XuatMang(int A[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
}
int main() {
    int a[MAXN], n;
    NhapMang(a, n);
    SapXepSoAmTangDan(a, n);
    XuatMang(a, n);
    return 0;
}
