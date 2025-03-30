#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX= int(2e5)+1;
#include<cstring>
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int Count=0;
    // int* used = new int(MAX); // sai đây là cấp phát 1 bộ nhớ có giá trị max
    int* used = new int[MAX];
    // memset(used,0,MAX);
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        if(!used[temp]){
            used[temp]=1;
            Count++;
        }
    }
    cout<<Count;
    delete[] used;
    return 0;
}
