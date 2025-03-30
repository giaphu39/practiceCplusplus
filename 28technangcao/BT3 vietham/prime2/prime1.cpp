#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long arr[1000000];
void sang(unsigned long long n){
    for(unsigned long long i=0;i<=n;i++){
        arr[i]=true;
    }
    arr[0]=arr[1]=false;
    for(unsigned long long i=2;i<=sqrt(n);i++){
        for(unsigned long long j=i*i;j<=n;j+=i){
            arr[j]=false;
        }

void giai(unsigned long long n){
    for(unsigned long long i=0;i<n;i++){
        if(i*i>n){
            break;
        }
        else if(arr[i]){
            cout<<i*i<<" ";
        }
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned long long n;
    cin>>n;
    sang(n);
    giai(n);
    return 0;
}
