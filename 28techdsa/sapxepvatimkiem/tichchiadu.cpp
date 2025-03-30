#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using ll=long long; //nhớ nhân nhau thì số rất lớn nên phải dùng kiểu long long
const int MOD = int(1e9)+7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;cin>>n;
    ll iSum=1;
    for(int i=0;i<n;i++){
        ll temp;cin>>temp;
        iSum*= (temp % MOD);
        iSum %=MOD;
    }   
    cout<<iSum;
    return 0;
}
