#include<iostream>
using namespace std;
#define M 100
using ll=long long;
void nhap(int& n, int arr[]){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

}

void in(int n, int arr[]){
    for(int i=1;i<n;i+=2){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    int arr[M];
    nhap(n,arr);
    in(n,arr);
    

}