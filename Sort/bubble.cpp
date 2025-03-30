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


int main() {
    int n;
    cin >> n;
    int arr[n];
    
    nhap(arr, n);
    bubble(arr,n);
    xuat(arr, n);

    return 0;
}
