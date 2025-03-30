// Write your code here
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    // unsigned int n,m,j;
    // int count=0;
    // int ans=0;
    // unsigned int  powerof10=1;
    // // cin>>n>>m;
    // j=n;
    // while(j!=0){
    //     j/=10;
    //     count++;
    // }
    // for(int i=0;i<count;i++){
    //     powerof10*=10;
    // }
    // cout << powerof10<<endl;
    // cout<<count<<endl;
    // for(int i=n;i<=m;i+=powerof10){
    //     if(i % powerof10 == m % powerof10){
    //         ans++;
    //     }
    // }
    int n,m,j;
    int ans;
    int count=0;
    int powerof10=1;
    cin>>n>>m;
    j=n;
    while(j!=0){
        j/=10;
        count++;
    }
    // cout<<count<<endl;
    for(int i=0;i<count;i++){
        powerof10*=10;
    }
    // cout<<powerof10<<endl;
    ans= (m-n) /powerof10 +1;
    cout<<ans;
    return 0;
}