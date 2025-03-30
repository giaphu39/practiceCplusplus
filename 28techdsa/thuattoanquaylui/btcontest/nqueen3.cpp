#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, hang[101];
int cot[101], xuoi[101], nguoc[101];

void sol(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(hang[i]==j) cout<<"Q";
            else cout<<".";
        }
        cout<<endl;
    }
    // cout<<endl;
}

void quaylui(int i){
    //thử các cách đặt cột trên hàng
    for(int j=1;j<=n;j++){
        if(!cot[j] && !xuoi[i-j+n] && !nguoc[i+j-1]){
            cot[j]=1;
            xuoi[i-j+n]=1;
            nguoc[i+j-1]=1;

            hang[i]=j;

            if(i==n){
                sol();
            }
            else quaylui(i+1);
            cot[j]=0;
            xuoi[i-j+n]=0;
            nguoc[i+j-1]=0;
        }
    }

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n;
    quaylui(1);    
    
    return 0;
}
