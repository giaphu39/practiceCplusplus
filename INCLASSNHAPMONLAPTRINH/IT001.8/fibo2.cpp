#include<iostream>
using namespace std;
const unsigned long long mod=1000000007;
unsigned long long arr[1000000];
unsigned long long fibo1(unsigned long long n){
    if(n<=1) return n % mod;
    else return fibo1(n-1)+fibo1(n-2);
}
unsigned long long fibo2(int n){
    unsigned long long f1=0, f2=1,fn;
    if(n==0) return 0; // nhớ các trường hợp đặc biệt ngoài vòng lặp
    else if(n<=2) return 1;
    for(unsigned long long i=2;i<=n;i++){
        fn=(f1+f2)%mod;
        f1=f2;
        f2=fn;
    }
    return fn;
}
int main(){
    unsigned long long n;
    cin>>n;
    cout<<fibo2(n);
    return 0;
}