#include<bits/stdc++.h>
using namespace std;

int n,arr[100];
void ketqua(){
    for(int i=1;i<=n;i++){
        cout<<arr[i];
    }
    cout<<endl;
}
void _try(int i){
    //duyệt các khả năng của x[i]
    // mà nhị phân chỉ có 2 khả năng 0 hoặc 1
    for(int j=0;j<=1;j++){
        arr[i]=j;
        if(i==n){ // chạy hết n
            ketqua();
        }
        else{
            _try(i+1); 
        }
    }
}

int main(){
    cin>>n;
    _try(1);
    return 0;
}