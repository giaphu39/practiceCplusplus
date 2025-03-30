 #include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
unsigned long long arr[1000000];
bool fibo2(unsigned long long n){
    if(n<=1){return true;}
    else{
        arr[0]=0;
        arr[1]=arr[2]=1;
        unsigned long long ind;
        for(unsigned long long i=3;;i++){
            arr[i]=arr[i-1]+arr[i-2];
            if(arr[i]>=n){
                ind=i;
                break;
            }
        }
        for(unsigned long long i=3;i<=ind;i++){
            if(arr[i]==n){
                return true;
            }
            //nhớ cẩn thận vị trí return
        }
        return false;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned long long n;
    cin>>n;
    if(fibo2(n)){cout<<"YES";}
    else cout<<"NO";
    return 0;
}
