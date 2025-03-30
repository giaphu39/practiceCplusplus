#include<bits/stdc++.h>
using namespace std;
unsigned long long ans;
void input(int& n){
    cin>>n;
}

void sol(int n){
    ans=0;
    for(int i=n;i>0;i--){
        int u=1;
        for(int j=1;j<=i;j++){
            u*=j;
        }
        ans+=u;
    }
}
int main(){

    int n;
    input(n);
    sol(n);
    cout<<ans;
    return 0;
}