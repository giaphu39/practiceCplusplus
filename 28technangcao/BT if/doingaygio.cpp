#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,nam,tuan,ngay;
    cin>>n>>nam>>tuan>>ngay;
    nam=n/365;
    if (n%365==0){
        tuan=0;
        ngay=0;
    }
    else{
        tuan=(n-nam*365)/7 ;
        if((n-nam*365)%7==0){
            ngay=0;
        }
        else{
            ngay=n-nam*365-(tuan)*7;
        }
        }
    
    cout<<nam<<" "<<tuan<<" "<<ngay;
    
    
    return 0;
}
