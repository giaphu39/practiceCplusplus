#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int ans=0, n, cot[100];
int hang[100], xuoi[100], nguoc[100];

int x[101][101];

void check(){
    int sum=0;
    for(int i=1;i<=n;i++){ // lặp qua từng phần tử mảng hang
        for(int j=1;j<=n;j++){ // lặp qua nếu cột được đánh dấu
        if(hang[i]==j){  // do mảng hàng lưu vị trí cột được đánh dấu
            sum+=x[i][j];
        }
            
        }
    }
    ans=max(ans, sum);
}

void quaylui(int i){
    

    for(int j=1;j<=n;j++){
        
        if(cot[j]==0 && xuoi[i-j+n]==0 && nguoc[i+j-1]==0){
            hang[i]=j; // lưu vị trí cột vào hàng
            cot[j]=1; xuoi[i-j+n]=1; nguoc[i+j-1]=1; // bịt lại chỗ đã đi

            if(i==n){
                check();
                
            }    
            else{
                quaylui(i+1);
            }
            cot[j]=0; xuoi[i-j+n]=0; nguoc[i+j-1]=0;

        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    n=8;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>x[i][j];
        }
    }
    quaylui(1);
    cout<<ans;
    return 0;
}
