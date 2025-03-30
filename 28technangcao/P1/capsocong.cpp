// Cho cấp số cộng có n phần tử, cho biết phần tử đầu tiên trong dãy là u1 và công sai d. Hãy tính tổng các phần tử của cấp số cộng này
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long u1,d,sn,n;
    cin>>n>>u1>>d;
    // sn=(n*(u1+(n-1)*d))/2.0; // sai do số ở trên có thể ra số lẻ mà chia 2 có thể bị làm tròn
    sn=n * u1 + ((n - 1) * n) / 2 * d; // đúng hơn do n*(n-1) luôn là số chẵn ( chẵn*lẻ= chẵn) chia ra không bị làm tròn
    cout<<sn;
    return 0;
}
