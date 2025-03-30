#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // int n;
    // long long ans;
    // cin>>n;
    // for(int i=1;i<=n;i++){
    //     ans+=(i*i);
    // }
    // cout<<ans;//sai 1 trường hợp

    int n;
    cin >> n;
    long long ans = (1LL * n * (n + 1) * (2 * n + 1)) / 6; //tự giải và suy ra công thức
    // đưa độ phức tạp O(n) sang O(1)
    cout << ans << endl;
    return 0;
}
