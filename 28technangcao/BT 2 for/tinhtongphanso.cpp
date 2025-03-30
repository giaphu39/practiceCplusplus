#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    long double ans=0; // sai do để kiểu long long 
    for(int i=2;i<=2*n;i+=2){
        ans+= 1.0/i; // sai do ghi 1/i
    }
    cout<<fixed<<setprecision(5)<<ans;
    return 0;
}
