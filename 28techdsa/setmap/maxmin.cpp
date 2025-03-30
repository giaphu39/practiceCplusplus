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


        auto it=a.begin();
        cout<<*it<<endl;
    }
    else if(type==4){
        auto it=a.rbegin();
        cout<<*it<<endl;
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

    int**b=new int*[q];
    for(int i=0;i<q;i++){
        b[i]=new int[2];
    }

    for(int i=0;i<q;i++){
        cin>>b[i][0];
        if(b[i][0]<=2) cin>>b[i][1]; // nho chu y cho nay
    }

    for(int i=0;i<q;i++){
        sol(b[i][0], b[i][1], a);
    }

    return 0;
}
