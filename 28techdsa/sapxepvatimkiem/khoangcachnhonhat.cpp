#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<climits>
//i va j khac nhau nhung co the gia tri giong

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin>>n;
    int d= INT_MAX;

    bool flag=0;

    vector<int> a;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        a.push_back(temp);
    }
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         flag=1;
    //         d=min(d,abs(a[i] - a[j]));
    //     }
    // }
    // if(!flag) cout<< 0;
    // else cout<<d;

    // cách tối ưu hơn là sắp xếp rồi tìm , nhớ bài toán tìm kiếm thì nên sort trước
    sort(a.begin(), a.end());
    
    if(a[0] == a[n-1]) cout<< 0;
    else{
        for(int i=0;i<n-1;i++){
            d= min( d, abs( a[i] - a[i+1]));
        }
        cout<<d;
    }

    return 0;
}
