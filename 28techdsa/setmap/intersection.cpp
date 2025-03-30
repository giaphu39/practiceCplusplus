#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<vector>
#include<set>
void output(int n,int m, vector<int> a, set<int> b){
        // int so=(a.second).first; // dung map thi chac chan key la so se khong hien lai
        // // loi vi map<map> thi phai duyet qua tung map nua 

        // if(b.find(s)) cout<<so<<" ";

        for(int i=0;i<a.size();i++){
            if(b.find(a[i])!=b.end()) cout<< a[i]<<" ";
        }

}

int main() {
    // dung mang de luu thu tu con set de tranh trung lap
    //nen dung vector de them phan tu vi de them vao hon mang

    int n;cin>>n;
    int m;cin>>m;
    // int* a=new int[n];
    vector<int> a;
    set<int> afake;
    set<int>b;
    for(int i=0;i<n;i++){
        int c;cin>>c;
        if(afake.find(c)==afake.end()){
            a.push_back(c);
            
        }
        afake.insert(c);
    }
    for(int i=0;i<m;i++){
        int c;cin>>c;
        b.insert(c);
    }
    output(n,m,a,b);
    return 0;
}
