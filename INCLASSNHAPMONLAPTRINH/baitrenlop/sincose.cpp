#include<iostream>
using namespace std;

long long factorial(long long a){
    if(a==0) return 1;
    int n=a-1;
    while(n!=0){
        a*=n;
        n--;
    }
    return a; 
}


int main(){
    int x;int e;
    cin>>x>>e;
    // cout<<factorial(0);
   //tính cos  
    long long ans=1;
    int dau=1;
    for(int i=2;;i+=2){
        
        ans+=((-1)*(dau++))
    }
    return 0;
}