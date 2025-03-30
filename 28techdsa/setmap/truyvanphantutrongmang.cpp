#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<map>
#include<set>

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin>>n;
    // set<int> a;
    // for(int i=0;i<n;i++){
    //     int b;cin>>b;
    //     a.insert(b);
    // }

    // int q;cin>>q;
    // for(int i=0;i<q;i++){
    //     int b;cin>>b;
    //     if(a.find(b)!=a.end()) cout<<"YES"<<endl;
    //     else cout<<"NO"<<endl;
    // }
    map<int,int> a;
    for(int i=0;i<n;i++){
        int b;cin>>b;
        a.insert({b,1});
    }
    
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int b;cin>>b;
        if(a.find(b)!=a.end()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
