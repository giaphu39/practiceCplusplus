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
void timmax2(int n, int arr[]){
    int max1=0;
    int max2=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max1){
            max1=arr[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>max2 and arr[i]!=max1){
            max2=arr[i];
        }
    }
    cout<<max2;
}

int main(){
    int n;
    int arr[MAX];
    nhap(n,arr);
    timmax2(n,arr);
    return 0;
}