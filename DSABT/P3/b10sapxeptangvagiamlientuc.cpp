/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include<iostream>
void XuatMang(int A[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
    std::cout << std::endl;
}

//###INSERT CODE HERE -
using namespace std;
#define MAXN 200
void luuvaomang(int b[], int* c, int *d, int* a, int n, int& b1, int& c1, int& d1){
    
    for(int i=0;i<n;i++){
        if(a[i]>0){
            b[b1++]=a[i];
        }
        else if(a[i] < 0){
            c[c1++]=a[i];
        }
        else{
            d[d1++] = a[i];
        }
    }
}
void sapxepduonggiam(int *a,int n){
    for(int i=0;i<n-1;i++){
            int iMax=i;
            for(int j=i+1;j<n;j++){
                if( a[j]> a[iMax]){
                    iMax=j;
                }
            }
            std::swap(a[i],a[iMax]);
        }
}
void sapxepamtang(int *a,int n){
    for(int i=0;i<n-1;i++){
            int iMin=i;
            for(int j=i+1;j<n;j++){
                if( a[j]< a[iMin]){
                    iMin=j;
                }
            }
            std::swap(a[i],a[iMin]);
        }
        
}
void SapXepSoDuongGiamAmTangVa0(int *a, int n){
    int b[MAXN]; // lưu số dương giảm dần
    int c[MAXN]; //số âm tăng dần
    int d[MAXN]; // lưu số 0
    int b1=0, c1=0, d1=0;
    luuvaomang(b,c,d,a,n, b1, c1, d1);

    // for(int i=0;i<n-1;i++){
    //     if(a[i] < 0){
    //         int iMin=i;
    //         for(int j=i+1;j<n;j++){
    //             if(a[j] < 0 && a[j]< a[iMin]){
    //                 iMin=j;
    //             }
    //         }
    //         std::swap(a[i],a[iMin]);
    //     }
        
    // }
    sapxepduonggiam(b,b1);
    sapxepamtang(c,c1);
    
    int i=0;
    for(int j=0;j<b1;j++){
        a[i++]=b[j];
    }
    for(int j=0;j<c1;j++){
        a[i++]=c[j];
    }
    for(int j=0;j<d1;j++){
        a[i++]=d[j];
    }
}
void NhapMang(int*a, int& n){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
int main() {
    int a[MAXN], n;
    NhapMang(a, n);
    SapXepSoDuongGiamAmTangVa0(a, n);
    XuatMang(a, n);
    return 0;
}










// // Hàm so sánh cho std::sort
// bool customSort(int x, int y) {
//     if ((x > 0 && y > 0) || (x < 0 && y < 0)) 
//         return x > y; // Số dương giảm dần, số âm giảm dần trước khi đảo ngược
//     if (x > 0) return true;  // Số dương đứng trước
//     if (y > 0) return false;
//     if (x == 0) return false; // Số 0 luôn đứng cuối
//     return true;
// }

// void SapXepSoDuongGiamAmTangVa0(int *a, int n) {
//     sort(a, a + n, customSort);
//     // Đảo ngược phần số âm để tăng dần
//     int i = 0;
//     while (i < n && a[i] > 0) i++; // Bỏ qua số dương
//     int j = i;
//     while (j < n && a[j] < 0) j++; // Đến hết số âm
//     reverse(a + i, a + j);
// }