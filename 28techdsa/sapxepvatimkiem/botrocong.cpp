#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = int(1e9)+7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;cin>>n;
    int iSum=0;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        iSum+= temp % MOD;
    }   
    cout<<iSum;
    return 0;
}
