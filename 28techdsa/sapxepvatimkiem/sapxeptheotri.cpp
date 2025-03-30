#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include<vector>

bool compare(int a, int b){
    // if(abs(a) != abs(b)){
        return abs(a) < abs(b);
    // }
    // return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        a.push_back(temp);
    }

    stable_sort(a.begin(), a.end(),compare);
    for(vector<int>::iterator it=a.begin(); it!=a.end(); it++){
        cout<<*it<<" ";
    }

    
    return 0;
}
