#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int ans=0, n, cot[100];
int hang[100], xuoi[100], nguoc[100];

void quaylui(int i){
    

    for(int j=1;j<=n;j++){
        
        if(cot[j]==0 && xuoi[i-j+n]==0 && nguoc[i+j-1]==0){
            hang[i]=j; // lưu vị trí cột vào hàng
            cot[j]=1; xuoi[i-j+n]=1; nguoc[i+j-1]=1; // bịt lại chỗ đã đi

            if(i==n){
                ans++;
                
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
    cin>>n;
    quaylui(1);
    cout<<ans;
    return 0;
}
