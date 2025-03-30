#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    // for(int i=1;i<=n;i++){
    //     int p=i*i;
    //     if(p<=n){
    //         cout<<p<<" ";
    //     }
    //     else break;
    // }
    // chưa được tối ưu tối đa 

    for(int i=1;i*i<=n;i++){
        cout<<i*i<<" ";
    }
    // vẫn bị lỗi do phải đặt n và i là kiểu long long 
    return 0;
}
