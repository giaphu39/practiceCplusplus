#include<iostream>
using namespace std;
int fibo1(int n){
    if(n<=1) return n;
    else return fibo1(n-1)+fibo1(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<fibo1(n);
    return 0;
}