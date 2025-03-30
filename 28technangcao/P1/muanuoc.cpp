#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// ý tưởng 1: lấy chai có giá thấp nhất là nhiều nhất còn lại là chai có giá cao ( nếu )
// ý tưởng 2: nếu giá 1 l thấp nhất thì lấy 1 lít hết còn giá 2 lít thấp thì lấy 2 lít trước còn lại là 1 lít

// sai chỗ if(a<=b) do có thể giá a/ 1 lít x 2 > giá b/2 lít
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a,b;
    long long n;
    cin>>n>>a>>b;
    if(a*2<=b){
        cout<<n*a;
    }
    else{
        int c=n%2;
        cout<< (n/2)*b + c*a;
    }
    
    return 0;
}
