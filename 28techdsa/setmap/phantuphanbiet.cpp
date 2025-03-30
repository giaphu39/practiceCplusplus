#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include<set>
#include<map>
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin>>n;
    // set<int> a;
    // for(int i=0;i<n;i++){
    //     int b;cin>>b;
    //     a.insert(b);
    // }
    // cout<<a.size();
    
    map<int,int> a;
    for(int i=0;i<n;i++){
        int b;cin>>b;
        // a.insert({b,1}); //dat gia tri co la 1
        a[b]=1;
    }
    cout<<a.size();

    return 0;
}
