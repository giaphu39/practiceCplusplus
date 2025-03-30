#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<set>
#include<vector>
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;cin>>n>>m;
    set<int> a;
    set<int> b;
    set<int> giao;
    for(int i=0;i<n;i++){
        int c;cin>>c;
        a.insert(c);
    }
    for(int i=0;i<m;i++){
        int c;cin>>c;
        b.insert(c);
        
    }
    //xuất hiện trong mảng 1 không xuất hiện trong mảng 2
    //lặp trong mảng 1 tìm mảng 2

    for(set<int>::iterator it=a.begin();it!=a.end();it++){
        if(b.find(*it)==b.end()){
            giao.insert(*it);
        }
    }


    for(set<int>::iterator it=giao.begin();it!=giao.end();it++){
        cout<<*it<<" ";
    }



    return 0;
}
