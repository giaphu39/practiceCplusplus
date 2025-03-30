#include <iostream>
using namespace std;

long long gtk(int n){
    long long ans=1;
    if(n%2==0){
        for(int i=2;i<=n;i+=2){
            ans*=i;
        }
    }
    else{
        for(int i=1;i<=n;i+=2){
            ans*=i;
        }
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    cout<<gtk(n);
}