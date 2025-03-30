#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<string>
using ll = long long;
int fibo[100];

string _try(int n, int k){

    if(n==1) return "28tech";
    if(n==2) return "c++";
    // if(n==3) return "DSA JAVA"; // chỗ này sai chỉ lấy 1 từ
    if(n==3){
        if(k==1) return "DSA";
        else return "JAVA";
    }
    if(k<= fibo[n-3]){
        return _try(n-3, k);
    }
    // else if(k<fibo[n-2]){// xét điều kiện khoảng sai
    else if(k<= fibo[n-3]+ fibo[n-2]){
        return _try(n-2,k-fibo[n-3]);
    }
    else{
        return _try(n-1,k-fibo[n-3]-fibo[n-2]);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   


    fibo[0]=0;fibo[1]=1;fibo[2]=1; fibo[3]=2;
    // do 28tech    c++     DSA JAVA=> lần lượt có số từ là 1 1 2
    for(int i=4;i<=98;i++){
        fibo[i]=fibo[i-1]+fibo[i-2];
    }

    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        cout<<_try(n,k);
    }

    return 0;
}
