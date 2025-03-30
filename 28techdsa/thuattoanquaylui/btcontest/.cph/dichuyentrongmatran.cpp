#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<string>
#include<utility>
int cou=0,m,n;

pair <int,int> moves[3]={{1,0},{0,1}};
string S="RD";

void quaylui(int i, int j){
    if(i==m-1 && j==n-1){
        cou++;
        return;
    }

    for(int z=0;z<2;z++){ // chỗ này quên đặt trùng tên i
        int i1= i+ moves[z].first;
        int j1= j+ moves[z].second;

        if(i1<m && j1<n ){
            quaylui(i1,j1);

        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>m>>n; // chỗ này ghi nhầm thành ,
    int ** a= new int*[m];
    for(int i=0;i<m;i++){
        a[i]=new int[n];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    quaylui(0,0);
    cout<<cou;
    delete[] a;

    return 0;
}
