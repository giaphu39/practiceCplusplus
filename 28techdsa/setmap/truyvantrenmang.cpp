#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<map>
#include<set>


void sol(int type, int x, multiset<int>& a){ // nho phai truyen tham chieu 
    if(type==1){
        a.insert(x);
    }
    else if(type==2){
        if(a.count(x)==0) return;
        else a.erase(x);
    }
    else if(type==3){
        if(a.count(x)!=0) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin>>n;
    multiset<int> a;
    for(int i=0;i<n;i++){
        int b;cin>>b;
        a.insert(b);
    }

    int q;cin>>q;
    int** b=new int*[q];
    for(int i=0;i<q;i++){
        b[i]=new int[2];
    }
    for(int i=0;i<q;i++){
        cin>>b[i][0]>>b[i][1];
    }

    for(int i=0;i<q;i++){
        sol(b[i][0], b[i][1],a);
    }


    // multimap<int,int> a;
    // for(int i=0;i<n;i++){
    //     int b;cin>>b;
    //     a.insert({b,1});
    //     if(a.count(b)==1) cout<<b<<" ";
    // }

    return 0;
}
