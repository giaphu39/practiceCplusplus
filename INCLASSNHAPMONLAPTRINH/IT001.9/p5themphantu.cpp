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

void themphantu(int& n, int arr[]){
    int x,k;
    cin>>x>>k;
    for(int i=n;i>=k;i--){//xét đẩy lên thì i phải bằng k lun sau đó mới gán cái mới tại vị trí k
        // arr[i]=arr[i-1];// lấy từ trên xuống vì sẽ không ảnh hưởng các phần tử trước
        //thay vì bỏ phía trước thì gán đẩy lên trước
        arr[i+1]=arr[i];
    }
    arr[k]=x;
    n++;

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
    nhap(n,arr);
    themphantu(n,arr);
    xuat(n,arr);
    return 0;
}