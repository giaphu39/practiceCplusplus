#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<string>
#include<utility>
int n, a[100][100], check=0;
string s;
// do bắt in theo thứ tự từ điển tăng dần nên theo bảng chữ cái DLRU

// string S="URDL";
// pair<int,int> ind[4]={{-1,0},{0,1},{1,0},{0,-1}};

string S="DLRU";
pair<int,int> ind[4]={{1,0},{0,-1},{0,1},{-1,0}};

void quaylui(int i, int j){
    
    if(i==n && j==n){
        cout<<s<<endl;
        check++;
        return;
    }

    for(int z=0;z<4;z++){
        int i1=i+ ind[z].first;
        int j1=j+ind[z].second;

        if(i1>=1 && j1>=1 && i1<=n && j1<=n && a[i1][j1]==1){
            s+=S[z];
            a[i1][j1]=0;

            quaylui(i1,j1);

            s.pop_back();
            a[i1][j1]=1;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
    quaylui(1,1);
    if(!check){
        cout<<-1;
    }
    return 0;
}
