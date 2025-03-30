#include<iostream>
using namespace std;
#include <climits>

int main(){ 
    int h,w;
    cin>>h>>w;
    int arr[500][500];//nhớ mảng 2 chiều phải khai báo vậy
    //500 là tối đa
    int ans=0;
    int min=1e9;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
            if(arr[i][j]<min) min=arr[i][j];
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            ans+=(arr[i][j]-min);
        }
    }
    cout<<ans;


    return 0;
}