#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
const long long MOD = 1000000007;
unsigned long long Fibo(long long x){ // phải dùng unsigned vì fibo rất lớn
    long long n1=0, n2=1, n;
    if(x<=2) n=1;
    else {for(int i=2;i<=x;i+=1){
        n = (n1 + n2) % MOD;
        n1=n2;
        n2=n;
    }}
    return n;
}

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long n;
    cin>>n;
    cout<<Fibo(n);
    return 0;
}