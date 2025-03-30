#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned long long n;
    int a,b,c,e,f;
    cin>>n>>a>>b;
    c=max(a,b);
    e=n/c;
    f=(n-e*c)/min(a,b);
    // cout<<e<<" "<<f;
    cout<<e*c+f*min(a,b);
    return 0;
}
