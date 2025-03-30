#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int cp[100][100];
int x[100]; // lưu thành phố nào đi tại lần đi thứ i
int sum=0;
int used[100]; // thành phố đã đi
int ans=INT_MAX;
int giatrimin=INT_MAX;
int n;
void quaylui(int i){ // i là lần đi thứ mấy
    for(int j=1;j<=n;j++){
        if(!used[j]){
            x[i]=j;
            used[j]=1;
            sum+= cp[x[i-1]][x[i]];

            if(i==n){
                ans=min(ans,sum+cp[x[i]][1]);
            }
            else if(sum+(n-i+1)*giatrimin<ans) quaylui(i+1);
            used[j]=0;
            sum-= cp[x[i-1]][x[i]];
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>cp[i][j];
            if(cp[i][j]) giatrimin=min(giatrimin,cp[i][j]);
        }
    }
    x[1]=1;
    used[1]=1;
    quaylui(2);
    cout<<ans;
    return 0;
}
