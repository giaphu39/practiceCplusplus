#include <iostream>
using namespace std;

void nhap(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void xuat(int arr[], int n) {  
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertion(int arr[],int n){
    for(int i=1;i<n;i++){ // ko được để dấu bằng vì sẽ truy cập ngoài mảng gây nên lỗi 
        int temp= arr[i];
        int j=i-1;
        while(arr[j]>temp and j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
int main() {
    int n;
    cin >> n;
    int arr[n];
    
    nhap(arr, n);
    insertion(arr,n);
    xuat(arr, n);

    return 0;
}
