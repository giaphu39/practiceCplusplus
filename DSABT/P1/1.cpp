#include<iostream>
#include<vector>
using namespace std;

void input(vector<int>& a, int n){

    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        a.push_back(temp);
    }
}

void LinearSearch(vector<int>& a, int x, int sl){

    a.push_back(x);
    int i=0;
    while(a[i] != x){
        i++;
    }
    if(i<sl) cout<<"true";
    else cout<<"false";
}
int main(){


    vector<int> a;

    int x;cin>>x;

    int sl;cin>>sl;

    input(a,sl);
    LinearSearch(a,x,sl);

    return 0;
}