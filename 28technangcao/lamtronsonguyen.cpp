#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    float a;
    cin>>a;
    // cout<<int (round(a));
    if(int(a*10) %10>5){
        cout<<int(a)+1;
    }
    else{
        cout<<int(a);
    }
    return 0;
}
