#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<set>
//nếu yêu cầu in ngược? bỏ vào vector rồi sort lại
#include<vector>
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;cin>>n>>m;
    set<int> a;
    set<int> b;
    set<int> hop;
    set<int> giao;
    for(int i=0;i<n;i++){
        int c;cin>>c;
        a.insert(c);
        hop.insert(c);
    }
    for(int i=0;i<m;i++){
        int c;cin>>c;
        b.insert(c);
        hop.insert(c);
        if(a.find(c)!=a.end()){
            giao.insert(c);
        }
    }

    for(set<int>::iterator it=giao.begin();it!=giao.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(set<int>::iterator it=hop.begin();it!=hop.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    //sort ngược lại
    vector<int> c(giao.begin(),giao.end());

    vector<int> d(hop.begin(),hop.end());

    sort(c.begin(),c.end(),greater<int>());

    for(int& x: c){
        cout<< x;
    }
    


    return 0;
}
