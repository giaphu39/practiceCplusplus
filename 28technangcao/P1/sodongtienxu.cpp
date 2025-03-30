#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long n,s;
    cin>>n>>s;
    if(s%n==0){
        cout<<s/n;
    }
    else{
        cout<<s/n+1;
    }
    
    return 0;
}
