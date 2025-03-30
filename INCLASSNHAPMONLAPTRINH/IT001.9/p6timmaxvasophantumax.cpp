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
void timmax(int n, int arr[]){
    int max=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<max<<endl;
    for(int i=0;i<n;i++){
        if(arr[i]==max){
            count++;
        }
    }
    cout<<count;
}

int main(){
    int n;
    int arr[MAX];
    nhap(n,arr);
    timmax(n,arr);
    return 0;
}