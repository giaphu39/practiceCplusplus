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
    // multiset<int> a;
    // for(int i=0;i<n;i++){
    //     int b;cin>>b;
    //     a.insert(b);
    //     if(a.count(b)==1) cout<< b<<" ";
    // }

    multimap<int,int> a;
    for(int i=0;i<n;i++){
        int b;cin>>b;
        a.insert({b,1});
        if(a.count(b)==1) cout<<b<<" ";
    }

    return 0;
}
