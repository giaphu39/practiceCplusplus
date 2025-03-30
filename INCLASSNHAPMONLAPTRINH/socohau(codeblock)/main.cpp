// Write your code here
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,m,j;
    int ans=0;
    int count=0;
    int powerof10=1;
    cin>>n>>m;
    j=n;
    while(j!=0){
        j/=10;
        count++;
    }
    cout<<count;
    for(int i=0;i<count;i++){
        powerof10*=10;
    }
    cout<<powerof10;
    // ans= (m-n) /powerof10 +1;
    // cout<<ans;
    return 0;
}
