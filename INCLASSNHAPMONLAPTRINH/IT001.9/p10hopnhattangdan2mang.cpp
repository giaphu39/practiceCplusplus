#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100
void nhap(int& n, int arr[]){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

}
void xoa(int& n,int arr[], int k){
    for(int i=k;i<=n;i++){
        arr[i]=arr[i+1];//gán chỗ bị xóa cho số phía sau
    }
    n--;
}

void xuat(int n, int a[]){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
// void hopnhat(int n1, int n2,int& n3, int a[], int b[], int c[]){
//     n3=n1+n2;
//     int l=0,j=0;
//     for(int i=0;i<n3;i++){
//         // if(l==n1 and j==n2) break; // bằng luôn l và j vì chúng được cộng trước rồi xét
//         if(l<n1){
//             if(a[l]<b[j]){ // nếu không có sau dấu and thì xét luôn a[l] vậy thì sẽ out range
//                 c[i]=a[l];
//                 l++;
//                 cout<<c[i]<<"x "; //từ debug này thấy số 0 bị chèn ở giữa là giá trị rác
//             }
//         }
//         else if(j<n2){
//             if(a[l]>b[j]){
//                 c[i]=b[j];
//                 j++;
//                 cout<<c[i]<<"u ";
//             }
//         }
//     }
// }
void hopnhat(int n1, int n2,int& n3, int a[], int b[], int c[]){
    n3=n1+n2;
    int l=0,j=0,i=0;
    while(l<n1 and j<n2){// nghĩa là chỉ cần 1 trường hợp chạy đến n trước thì sẽ dừng liên
        if(a[l]<b[j]){
            c[i]=a[l];
            i++;l++;
        }
        else{
            c[i]=b[j];
            i++;j++;
        }
    }
    //in ra số còn lại của mảng còn lại
    while(l<n1){
        c[i]=a[l];i++;l++;
    }
    while(j<n2){
        c[i]=b[j];i++;j++;
    }
}



int main(){
    int n1,n2,n3;
    int a[MAX];
    int b[MAX];
    int c[MAX];
    nhap(n1,a);
    nhap(n2,b);
    hopnhat(n1,n2,n3,a,b,c);
    xuat(n3,c);
    return 0;
}