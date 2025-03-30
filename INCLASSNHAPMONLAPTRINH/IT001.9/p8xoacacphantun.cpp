#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100
void nhap(int& n, int arr[], int& x){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>x;

}
void xoa(int& n,int arr[], int k){
    for(int i=k;i<=n;i++){
        arr[i]=arr[i+1];//gán chỗ bị xóa cho số phía sau
    }
    n--;
}
void xoax(int& n, int arr[],int x){
    int u=n;
    for(int i=0;i<u;i++){
        if(arr[i]==x){
            xoa(n,arr,i);//như vậy thì n đổi liên tục, i cũng đổi liên tây
            i--; // tại sao?
        }
    }
}
// void xoax(int& n,int arr[],int x){
//     int b[MAX];
//     int j=0;
//     for(int i=0;i<n;i++){
//         if(arr[i]!=x){
//             b[j]=arr[i];
//             j++;
//         }
//     }
//     for(int i=0;i<=j;i++){
//         arr[i]=b[i];
//     }
//     n=j;
// }
void xuat(int n, int a[]){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    int arr[MAX];
    int x;
    nhap(n,arr,x);
    xoax(n,arr,x);
    xuat(n,arr);
    return 0;
}