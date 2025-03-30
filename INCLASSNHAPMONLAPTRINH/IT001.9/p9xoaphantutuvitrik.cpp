#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100
void nhap(int& n, int arr[], int& x, int& k){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>x;
    cin>>k;

}
void xoa(int& n,int arr[], int k){
    for(int i=k;i<=n;i++){
        arr[i]=arr[i+1];//gán chỗ bị xóa cho số phía sau
    }
    n--;
}
void xoax(int& n,int arr[],int p, int k){
    int b[MAX];
    int j=0;
    for(int i=0;i<p;i++){
        b[j]=arr[i];
        j++;
    }
    for(int i=p+k;i<n;i++){
        b[j]=arr[i];
        j++;
    }
    for(int i=0;i<=j;i++){
        arr[i]=b[i];
    } 
    n=j;
}
void xuat(int n, int a[]){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    int arr[MAX];
    int k,p;
    nhap(n,arr,p,k);
    xoax(n,arr,p,k);
    xuat(n,arr);
    return 0;
}