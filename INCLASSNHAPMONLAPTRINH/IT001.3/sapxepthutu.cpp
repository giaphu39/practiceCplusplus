// Write your code here
#include<bits/stdc++.h>
using namespace std;
int main(){
    float a,b,c;
    cin>>a>>b>>c;
    //sai và thiếu giá trị trùng lặp
    // cout<<min({a,b,c})<<" ";
    // if(a>min({a,b,c})and a<max({a,b,c})){
    //     cout<<a<<" ";
    // }
    // else if(b>min({a,b,c})and b<max({a,b,c})){
    //     cout<<b<<" ";
    // }
    // else {
    //     cout<<c<<" ";
    // }
    // cout<<max({a,b,c});
    
    //set sai vì chắc chắn có giá trị trùng lặp bị xoá, lúc đầu sai do lặp int x thì sẽ làm đổi giá trị
    // set<double> se;
    // se.insert(a);
    // se.insert(b);
    // se.insert(c);
    // for(double x:se){
    //     cout<<x<<" ";
    // }
    multiset<double> se;
    se.insert(a);
    se.insert(b);
    se.insert(c);
    for(double x:se){
        cout<<x<<" ";
    }
    // double x=[];
    // x.insert(a);
    // x.insert(b);
    // x.insert(c);
    // x.sort();
    // for(int i:x){
    //     cout<<i<<" ";
    // }
    
    return 0;
}